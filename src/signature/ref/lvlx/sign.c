#include <signature.h>
#include <tools.h>
#include <quaternion_data.h>
#include <id2iso.h>
#include <torsion_constants.h>
#include <encoded_sizes.h>


// TODO: need to clean up this file to remove unused functions

int
protocols_sign(signature_t *sig, const public_key_t *pk, secret_key_t *sk, const unsigned char *m, size_t l)
{
    int ret = 0;

    ec_curve_t E_rsp;
    ec_basis_t Brsp0;
    ibz_mat_2x2_t mat_Brsp_to_Brsp_can;
    ibz_mat_2x2_init(&mat_Brsp_to_Brsp_can);
    
    
    // computing the challenge with counter
    ibz_t challenge_degree;
    ibz_init(&challenge_degree);
    // Set counter to 0 if signing 
    uint32_t counter = 0;
    hash_to_challenge(&challenge_degree, m, pk, l, &counter);

    // adding counter to the signature
    sig->counter = counter;

#ifndef NDEBUG
    // Test that the counter is working
    ibz_t test;
    ibz_init(&test);
    hash_to_challenge(&test, m, pk, l, &sig->counter);
    assert(ibz_cmp(&test, &challenge_degree) == 0);
#endif

    // now we compute the response ideal by sampling a random ideal norm q (2^a -q)
    // computing the norm
    ibz_t tmp;
    ibz_init(&tmp);
    ibz_pow(&tmp,&ibz_const_two,A_POWER);
    ibz_sub(&tmp,&tmp,&challenge_degree);
    ibz_mul(&tmp,&tmp,&challenge_degree);

    // sampling the ideal
    quat_left_ideal_t lideal_resp;
    quat_left_ideal_init(&lideal_resp);

    
    // iterating until a solution has been found
    while (!ret) {
        ret = quat_sampling_random_ideal_O0_given_norm(
            &lideal_resp, &tmp, 0, &QUAT_represent_integer_params, &challenge_degree);
    }

    

    // intersection with the secret key
    quat_lideal_inter(&lideal_resp,&sk->secret_ideal,&lideal_resp,&QUATALG_PINFTY);

    // now we evaluate this isogeny on the basis of E0
    dim2id2iso_arbitrary_isogeny_evaluation(&Brsp0, &E_rsp, &lideal_resp);
    
    // notational conventions:
    // B0 = canonical basis of E0
    // Brsp0 = image through isogeny of canonical basis of E0

#ifndef NDEBUG
    // testing
    assert(test_point_order_twof(&Brsp0.P, &E_rsp, TORSION_EVEN_POWER));
    assert(test_point_order_twof(&Brsp0.Q, &E_rsp, TORSION_EVEN_POWER));
    assert(test_point_order_twof(&Brsp0.PmQ, &E_rsp, TORSION_EVEN_POWER));
#endif

    // now it only remains to format the response for the verification
    // canonical basis
    ec_basis_t B_rsp_can;

    // t = tic();
    ec_curve_normalize_A24(&E_rsp);
    ec_curve_to_basis_2f_to_hint(&B_rsp_can, &E_rsp, TORSION_EVEN_POWER);

    // compute the matrix to go from B_rsp_can to Brsp0
    change_of_basis_matrix_tate(&mat_Brsp_to_Brsp_can,
                               &Brsp0,                               
                               &B_rsp_can,
                               &E_rsp,
                               TORSION_EVEN_POWER);

    // now we multiply by the public key matrix
    ibz_2x2_mul_mod(&mat_Brsp_to_Brsp_can,&mat_Brsp_to_Brsp_can,&sk->mat_BAcan_to_BA0_two,&TORSION_PLUS_2POWER);

    // and now we multiply by the inverse of q mod 2^f
    ibz_invmod(&tmp,&challenge_degree,&TORSION_PLUS_2POWER);
    ibz_mul(&mat_Brsp_to_Brsp_can[0][0],&mat_Brsp_to_Brsp_can[0][0],&tmp); 
    ibz_mul(&mat_Brsp_to_Brsp_can[0][1],&mat_Brsp_to_Brsp_can[0][1],&tmp);
    ibz_mul(&mat_Brsp_to_Brsp_can[1][0],&mat_Brsp_to_Brsp_can[1][0],&tmp);
    ibz_mul(&mat_Brsp_to_Brsp_can[1][1],&mat_Brsp_to_Brsp_can[1][1],&tmp);

    // computing the actual basis
    matrix_application_even_basis(&B_rsp_can,&E_rsp,&mat_Brsp_to_Brsp_can,TORSION_EVEN_POWER);
    
    
    // Multiply the basis by 2^{TORSION_EVEN_POWER-A_POWER} 
    // int diff = TORSION_EVEN_POWER - A_POWER;
    // ec_dbl_iter_basis(&B_rsp_can, diff, &B_rsp_can, &E_rsp);
    // assert(test_basis_order_twof(&B_rsp_can, &E_rsp, A_POWER));

    // Filling the output
    assert(test_basis_order_twof(&B_rsp_can, &E_rsp, TORSION_EVEN_POWER));
    int diff = TORSION_EVEN_POWER - A_POWER - 2;
    ec_dbl_iter_basis(&B_rsp_can, diff, &B_rsp_can, &E_rsp);
    copy_basis(&sig->B_rsp,&B_rsp_can);
    

    // setting sig->E_rsp
    sig->E_rsp = E_rsp;

    quat_left_ideal_finalize(&lideal_resp);

    ibz_finalize(&challenge_degree);
    ibz_finalize(&tmp);

    return ret;
}

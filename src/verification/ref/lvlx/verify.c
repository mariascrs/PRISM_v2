#include <verification.h>
#include <mp.h>
#include <hd.h>
#include <encoded_sizes.h>
#include <assert.h>

// PRISM verification
int
protocols_verify(signature_t *sig, const public_key_t *pk, const unsigned char *m, size_t l)
{
    int verify;

    // recomputing the challenge degree
    ibz_t chall_degree;
    hash_to_challenge(&chall_degree, m, pk, l, &sig->counter);

    // computation of the challenge
    ec_basis_t B_pk_can, B_rsp_can;
    ec_curve_t Epk, Ersp;
    copy_curve(&Epk, &pk->curve);
    copy_curve(&Ersp, &sig->E_rsp);

    ec_normalize_curve_and_A24(&Ersp);
    ec_normalize_curve_and_A24(&Epk);
    copy_basis(&B_rsp_can, &sig->B_rsp);
    // assert(test_basis_order_twof(&B_rsp_can, &Ersp, TORSION_EVEN_POWER));
    ec_curve_to_basis_2f_from_hint(&B_pk_can, &Epk, TORSION_EVEN_POWER, pk->hint_pk); 
    // assert(test_basis_order_twof(&B_rsp_can, &Ersp, A_POWER));

    bool extra_torsion = true;
    int diff = TORSION_EVEN_POWER - A_POWER - 2;
    ec_dbl_iter_basis(&B_pk_can, diff, &B_pk_can, &Epk);
    // assert(test_basis_order_twof(&B_rsp_can, &Ersp, TORSION_EVEN_POWER - diff));
    // assert(test_basis_order_twof(&B_pk_can, &Epk, TORSION_EVEN_POWER - diff));

    // Set up domain product of curves 
    theta_couple_curve_t E0xErsp;
    copy_curve(&E0xErsp.E1, &Epk);
    copy_curve(&E0xErsp.E2, &Ersp);
    ec_normalize_curve_and_A24(&E0xErsp.E1);
    ec_normalize_curve_and_A24(&E0xErsp.E2);

    // Set-up the kernel
    theta_kernel_couple_points_t ker;
    copy_bases_to_kernel(&ker, &B_pk_can, &B_rsp_can);

    // Compute weil pairing before applying isogeny
    theta_couple_point_t P, Q, PmQ;
    
    
    int exp = TORSION_EVEN_POWER - diff - A_POWER;
    if(exp){
        ec_dbl_iter_basis(&B_pk_can, exp, &B_pk_can, &Epk);
    }
    assert(test_basis_order_twof(&B_pk_can, &Epk, A_POWER));
    fp2_t w0;
    weil_basis(&w0, A_POWER, &B_pk_can, &Epk);


    // Points to evaluate
    copy_point(&P.P1, &B_pk_can.P);
    copy_point(&Q.P1, &B_pk_can.Q);
    copy_point(&PmQ.P1, &B_pk_can.PmQ);
    ec_point_init(&P.P2);
    ec_point_init(&Q.P2);
    ec_point_init(&PmQ.P2);
    
    theta_couple_point_t pushed_points[3];
    pushed_points[0] = P;
    pushed_points[1] = Q;
    pushed_points[2] = PmQ;
    int len = sizeof(pushed_points) / sizeof(*pushed_points);
    
    theta_couple_curve_t codomain;
    
    // This should be true?
    verify = theta_chain_compute_and_eval_verify(
        A_POWER, &E0xErsp, &ker, extra_torsion, &codomain, pushed_points, len);
    

        if(verify){
            fp2_t w1,pow,invpow;

            digit_t digit_q[NWORDS_ORDER]={0};
            ibz_to_digit_array(digit_q, &chall_degree);
            fp2_pow_vartime(&pow, &w0, digit_q, NWORDS_ORDER);
            fp2_copy(&invpow,&pow);
            fp2_inv(&invpow);


            ec_curve_t Ecod1;
            copy_curve(&Ecod1, &codomain.E1);
            ec_curve_normalize_A24(&Ecod1);
            ec_point_t P1, Q1, PmQ1;
            copy_point(&P1, &pushed_points[0].P1);
            copy_point(&Q1, &pushed_points[1].P1);
            copy_point(&PmQ1, &pushed_points[2].P1);
            weil(&w1, A_POWER, &P1, &Q1, &PmQ1, &Ecod1);

            verify = (fp2_is_equal(&pow,&w1) || fp2_is_equal(&w1,&invpow));
    }

    return verify;
}


    
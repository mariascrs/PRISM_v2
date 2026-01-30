
#ifndef PRISM_NAMESPACE_H
#define PRISM_NAMESPACE_H

//#define DISABLE_NAMESPACING

#if defined(_WIN32)
#define PRISM_API __declspec(dllexport)
#else
#define PRISM_API __attribute__((visibility("default")))
#endif

#define PARAM_JOIN3_(a, b, c) prism_##a##_##b##_##c
#define PARAM_JOIN3(a, b, c) PARAM_JOIN3_(a, b, c)
#define PARAM_NAME3(end, s) PARAM_JOIN3(PRISM_VARIANT, end, s)

#define PARAM_JOIN2_(a, b) prism_##a##_##b
#define PARAM_JOIN2(a, b) PARAM_JOIN2_(a, b)
#define PARAM_NAME2(end, s) PARAM_JOIN2(end, s)

#ifndef DISABLE_NAMESPACING
#define PRISM_NAMESPACE_GENERIC(s) PARAM_NAME2(gen, s)
#else
#define PRISM_NAMESPACE_GENERIC(s) s
#endif

#if defined(PRISM_VARIANT) && !defined(DISABLE_NAMESPACING)
#if defined(PRISM_BUILD_TYPE_REF)
#define PRISM_NAMESPACE(s) PARAM_NAME3(ref, s)
#elif defined(PRISM_BUILD_TYPE_OPT)
#define PRISM_NAMESPACE(s) PARAM_NAME3(opt, s)
#elif defined(PRISM_BUILD_TYPE_BROADWELL)
#define PRISM_NAMESPACE(s) PARAM_NAME3(broadwell, s)
#elif defined(PRISM_BUILD_TYPE_ARM64CRYPTO)
#define PRISM_NAMESPACE(s) PARAM_NAME3(arm64crypto, s)
#else
#error "Build type not known"
#endif

#else
#define PRISM_NAMESPACE(s) s
#endif

// Namespacing symbols exported from algebra.c:
#undef quat_alg_add
#undef quat_alg_conj
#undef quat_alg_coord_mul
#undef quat_alg_elem_copy
#undef quat_alg_elem_copy_ibz
#undef quat_alg_elem_equal
#undef quat_alg_elem_is_zero
#undef quat_alg_elem_mul_by_scalar
#undef quat_alg_elem_set
#undef quat_alg_equal_denom
#undef quat_alg_init_set_ui
#undef quat_alg_make_primitive
#undef quat_alg_mul
#undef quat_alg_norm
#undef quat_alg_normalize
#undef quat_alg_scalar
#undef quat_alg_sub

#define quat_alg_add                                    PRISM_NAMESPACE_GENERIC(quat_alg_add)
#define quat_alg_conj                                   PRISM_NAMESPACE_GENERIC(quat_alg_conj)
#define quat_alg_coord_mul                              PRISM_NAMESPACE_GENERIC(quat_alg_coord_mul)
#define quat_alg_elem_copy                              PRISM_NAMESPACE_GENERIC(quat_alg_elem_copy)
#define quat_alg_elem_copy_ibz                          PRISM_NAMESPACE_GENERIC(quat_alg_elem_copy_ibz)
#define quat_alg_elem_equal                             PRISM_NAMESPACE_GENERIC(quat_alg_elem_equal)
#define quat_alg_elem_is_zero                           PRISM_NAMESPACE_GENERIC(quat_alg_elem_is_zero)
#define quat_alg_elem_mul_by_scalar                     PRISM_NAMESPACE_GENERIC(quat_alg_elem_mul_by_scalar)
#define quat_alg_elem_set                               PRISM_NAMESPACE_GENERIC(quat_alg_elem_set)
#define quat_alg_equal_denom                            PRISM_NAMESPACE_GENERIC(quat_alg_equal_denom)
#define quat_alg_init_set_ui                            PRISM_NAMESPACE_GENERIC(quat_alg_init_set_ui)
#define quat_alg_make_primitive                         PRISM_NAMESPACE_GENERIC(quat_alg_make_primitive)
#define quat_alg_mul                                    PRISM_NAMESPACE_GENERIC(quat_alg_mul)
#define quat_alg_norm                                   PRISM_NAMESPACE_GENERIC(quat_alg_norm)
#define quat_alg_normalize                              PRISM_NAMESPACE_GENERIC(quat_alg_normalize)
#define quat_alg_scalar                                 PRISM_NAMESPACE_GENERIC(quat_alg_scalar)
#define quat_alg_sub                                    PRISM_NAMESPACE_GENERIC(quat_alg_sub)

// Namespacing symbols exported from api.c:
#undef crypto_sign
#undef crypto_sign_keypair
#undef crypto_sign_open

#define crypto_sign                                     PRISM_NAMESPACE(crypto_sign)
#define crypto_sign_keypair                             PRISM_NAMESPACE(crypto_sign_keypair)
#define crypto_sign_open                                PRISM_NAMESPACE(crypto_sign_open)

// Namespacing symbols exported from basis.c:
#undef ec_curve_to_basis_2f_from_hint
#undef ec_curve_to_basis_2f_to_hint
#undef ec_recover_y
#undef lift_basis
#undef lift_basis_normalized

#define ec_curve_to_basis_2f_from_hint                  PRISM_NAMESPACE(ec_curve_to_basis_2f_from_hint)
#define ec_curve_to_basis_2f_to_hint                    PRISM_NAMESPACE(ec_curve_to_basis_2f_to_hint)
#define ec_recover_y                                    PRISM_NAMESPACE(ec_recover_y)
#define lift_basis                                      PRISM_NAMESPACE(lift_basis)
#define lift_basis_normalized                           PRISM_NAMESPACE(lift_basis_normalized)

// Namespacing symbols exported from biextension.c:
#undef clear_cofac
#undef ec_dlog_2_tate
#undef ec_dlog_2_weil
#undef fp2_frob
#undef reduced_tate
#undef weil

#define clear_cofac                                     PRISM_NAMESPACE(clear_cofac)
#define ec_dlog_2_tate                                  PRISM_NAMESPACE(ec_dlog_2_tate)
#define ec_dlog_2_weil                                  PRISM_NAMESPACE(ec_dlog_2_weil)
#define fp2_frob                                        PRISM_NAMESPACE(fp2_frob)
#define reduced_tate                                    PRISM_NAMESPACE(reduced_tate)
#define weil                                            PRISM_NAMESPACE(weil)

// Namespacing symbols exported from common.c:
#undef hash_to_challenge
#undef public_key_finalize
#undef public_key_init

#define hash_to_challenge                               PRISM_NAMESPACE(hash_to_challenge)
#define public_key_finalize                             PRISM_NAMESPACE(public_key_finalize)
#define public_key_init                                 PRISM_NAMESPACE(public_key_init)

// Namespacing symbols exported from dim2.c:
#undef ibz_2x2_mul_mod
#undef ibz_mat_2x2_add
#undef ibz_mat_2x2_copy
#undef ibz_mat_2x2_det_from_ibz
#undef ibz_mat_2x2_eval
#undef ibz_mat_2x2_inv_mod
#undef ibz_mat_2x2_set
#undef ibz_vec_2_set

#define ibz_2x2_mul_mod                                 PRISM_NAMESPACE_GENERIC(ibz_2x2_mul_mod)
#define ibz_mat_2x2_add                                 PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_add)
#define ibz_mat_2x2_copy                                PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_copy)
#define ibz_mat_2x2_det_from_ibz                        PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_det_from_ibz)
#define ibz_mat_2x2_eval                                PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_eval)
#define ibz_mat_2x2_inv_mod                             PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_inv_mod)
#define ibz_mat_2x2_set                                 PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_set)
#define ibz_vec_2_set                                   PRISM_NAMESPACE_GENERIC(ibz_vec_2_set)

// Namespacing symbols exported from dim2id2iso.c:
#undef dim2id2iso_arbitrary_isogeny_evaluation
#undef dim2id2iso_ideal_to_isogeny_clapotis
#undef find_uv
#undef fixed_degree_isogeny_and_eval

#define dim2id2iso_arbitrary_isogeny_evaluation         PRISM_NAMESPACE(dim2id2iso_arbitrary_isogeny_evaluation)
#define dim2id2iso_ideal_to_isogeny_clapotis            PRISM_NAMESPACE(dim2id2iso_ideal_to_isogeny_clapotis)
#define find_uv                                         PRISM_NAMESPACE(find_uv)
#define fixed_degree_isogeny_and_eval                   PRISM_NAMESPACE(fixed_degree_isogeny_and_eval)

// Namespacing symbols exported from dim4.c:
#undef ibz_inv_dim4_make_coeff_mpm
#undef ibz_inv_dim4_make_coeff_pmp
#undef ibz_mat_4x4_copy
#undef ibz_mat_4x4_equal
#undef ibz_mat_4x4_eval
#undef ibz_mat_4x4_eval_t
#undef ibz_mat_4x4_gcd
#undef ibz_mat_4x4_identity
#undef ibz_mat_4x4_inv_with_det_as_denom
#undef ibz_mat_4x4_is_identity
#undef ibz_mat_4x4_mul
#undef ibz_mat_4x4_negate
#undef ibz_mat_4x4_scalar_div
#undef ibz_mat_4x4_scalar_mul
#undef ibz_mat_4x4_transpose
#undef ibz_mat_4x4_zero
#undef ibz_vec_4_add
#undef ibz_vec_4_content
#undef ibz_vec_4_copy
#undef ibz_vec_4_copy_ibz
#undef ibz_vec_4_is_zero
#undef ibz_vec_4_linear_combination
#undef ibz_vec_4_negate
#undef ibz_vec_4_scalar_div
#undef ibz_vec_4_scalar_mul
#undef ibz_vec_4_set
#undef ibz_vec_4_sub
#undef quat_qf_eval

#define ibz_inv_dim4_make_coeff_mpm                     PRISM_NAMESPACE_GENERIC(ibz_inv_dim4_make_coeff_mpm)
#define ibz_inv_dim4_make_coeff_pmp                     PRISM_NAMESPACE_GENERIC(ibz_inv_dim4_make_coeff_pmp)
#define ibz_mat_4x4_copy                                PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_copy)
#define ibz_mat_4x4_equal                               PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_equal)
#define ibz_mat_4x4_eval                                PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_eval)
#define ibz_mat_4x4_eval_t                              PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_eval_t)
#define ibz_mat_4x4_gcd                                 PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_gcd)
#define ibz_mat_4x4_identity                            PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_identity)
#define ibz_mat_4x4_inv_with_det_as_denom               PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_inv_with_det_as_denom)
#define ibz_mat_4x4_is_identity                         PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_is_identity)
#define ibz_mat_4x4_mul                                 PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_mul)
#define ibz_mat_4x4_negate                              PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_negate)
#define ibz_mat_4x4_scalar_div                          PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_scalar_div)
#define ibz_mat_4x4_scalar_mul                          PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_scalar_mul)
#define ibz_mat_4x4_transpose                           PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_transpose)
#define ibz_mat_4x4_zero                                PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_zero)
#define ibz_vec_4_add                                   PRISM_NAMESPACE_GENERIC(ibz_vec_4_add)
#define ibz_vec_4_content                               PRISM_NAMESPACE_GENERIC(ibz_vec_4_content)
#define ibz_vec_4_copy                                  PRISM_NAMESPACE_GENERIC(ibz_vec_4_copy)
#define ibz_vec_4_copy_ibz                              PRISM_NAMESPACE_GENERIC(ibz_vec_4_copy_ibz)
#define ibz_vec_4_is_zero                               PRISM_NAMESPACE_GENERIC(ibz_vec_4_is_zero)
#define ibz_vec_4_linear_combination                    PRISM_NAMESPACE_GENERIC(ibz_vec_4_linear_combination)
#define ibz_vec_4_negate                                PRISM_NAMESPACE_GENERIC(ibz_vec_4_negate)
#define ibz_vec_4_scalar_div                            PRISM_NAMESPACE_GENERIC(ibz_vec_4_scalar_div)
#define ibz_vec_4_scalar_mul                            PRISM_NAMESPACE_GENERIC(ibz_vec_4_scalar_mul)
#define ibz_vec_4_set                                   PRISM_NAMESPACE_GENERIC(ibz_vec_4_set)
#define ibz_vec_4_sub                                   PRISM_NAMESPACE_GENERIC(ibz_vec_4_sub)
#define quat_qf_eval                                    PRISM_NAMESPACE_GENERIC(quat_qf_eval)

// Namespacing symbols exported from ec.c:
#undef cswap_points
#undef ec_biscalar_mul
#undef ec_curve_init
#undef ec_curve_init_from_A
#undef ec_curve_normalize_A24
#undef ec_curve_verify_A
#undef ec_dbl
#undef ec_dbl_iter
#undef ec_dbl_iter_basis
#undef ec_has_zero_coordinate
#undef ec_is_basis_four_torsion
#undef ec_is_equal
#undef ec_is_four_torsion
#undef ec_is_two_torsion
#undef ec_is_zero
#undef ec_j_inv
#undef ec_ladder3pt
#undef ec_mul
#undef ec_normalize_curve
#undef ec_normalize_curve_and_A24
#undef ec_normalize_point
#undef ec_point_init
#undef select_point
#undef xADD
#undef xDBL
#undef xDBLADD
#undef xDBLMUL
#undef xDBL_A24
#undef xDBL_E0
#undef xMUL

#define cswap_points                                    PRISM_NAMESPACE(cswap_points)
#define ec_biscalar_mul                                 PRISM_NAMESPACE(ec_biscalar_mul)
#define ec_curve_init                                   PRISM_NAMESPACE(ec_curve_init)
#define ec_curve_init_from_A                            PRISM_NAMESPACE(ec_curve_init_from_A)
#define ec_curve_normalize_A24                          PRISM_NAMESPACE(ec_curve_normalize_A24)
#define ec_curve_verify_A                               PRISM_NAMESPACE(ec_curve_verify_A)
#define ec_dbl                                          PRISM_NAMESPACE(ec_dbl)
#define ec_dbl_iter                                     PRISM_NAMESPACE(ec_dbl_iter)
#define ec_dbl_iter_basis                               PRISM_NAMESPACE(ec_dbl_iter_basis)
#define ec_has_zero_coordinate                          PRISM_NAMESPACE(ec_has_zero_coordinate)
#define ec_is_basis_four_torsion                        PRISM_NAMESPACE(ec_is_basis_four_torsion)
#define ec_is_equal                                     PRISM_NAMESPACE(ec_is_equal)
#define ec_is_four_torsion                              PRISM_NAMESPACE(ec_is_four_torsion)
#define ec_is_two_torsion                               PRISM_NAMESPACE(ec_is_two_torsion)
#define ec_is_zero                                      PRISM_NAMESPACE(ec_is_zero)
#define ec_j_inv                                        PRISM_NAMESPACE(ec_j_inv)
#define ec_ladder3pt                                    PRISM_NAMESPACE(ec_ladder3pt)
#define ec_mul                                          PRISM_NAMESPACE(ec_mul)
#define ec_normalize_curve                              PRISM_NAMESPACE(ec_normalize_curve)
#define ec_normalize_curve_and_A24                      PRISM_NAMESPACE(ec_normalize_curve_and_A24)
#define ec_normalize_point                              PRISM_NAMESPACE(ec_normalize_point)
#define ec_point_init                                   PRISM_NAMESPACE(ec_point_init)
#define select_point                                    PRISM_NAMESPACE(select_point)
#define xADD                                            PRISM_NAMESPACE(xADD)
#define xDBL                                            PRISM_NAMESPACE(xDBL)
#define xDBLADD                                         PRISM_NAMESPACE(xDBLADD)
#define xDBLMUL                                         PRISM_NAMESPACE(xDBLMUL)
#define xDBL_A24                                        PRISM_NAMESPACE(xDBL_A24)
#define xDBL_E0                                         PRISM_NAMESPACE(xDBL_E0)
#define xMUL                                            PRISM_NAMESPACE(xMUL)

// Namespacing symbols exported from ec_jac.c:
#undef ADD
#undef DBL
#undef DBLW
#undef copy_jac_point
#undef jac_from_ws
#undef jac_init
#undef jac_is_equal
#undef jac_neg
#undef jac_to_ws
#undef jac_to_xz
#undef jac_to_xz_add_components
#undef select_jac_point

#define ADD                                             PRISM_NAMESPACE(ADD)
#define DBL                                             PRISM_NAMESPACE(DBL)
#define DBLW                                            PRISM_NAMESPACE(DBLW)
#define copy_jac_point                                  PRISM_NAMESPACE(copy_jac_point)
#define jac_from_ws                                     PRISM_NAMESPACE(jac_from_ws)
#define jac_init                                        PRISM_NAMESPACE(jac_init)
#define jac_is_equal                                    PRISM_NAMESPACE(jac_is_equal)
#define jac_neg                                         PRISM_NAMESPACE(jac_neg)
#define jac_to_ws                                       PRISM_NAMESPACE(jac_to_ws)
#define jac_to_xz                                       PRISM_NAMESPACE(jac_to_xz)
#define jac_to_xz_add_components                        PRISM_NAMESPACE(jac_to_xz_add_components)
#define select_jac_point                                PRISM_NAMESPACE(select_jac_point)

// Namespacing symbols exported from encode_signature.c:
#undef secret_key_from_bytes
#undef secret_key_to_bytes

#define secret_key_from_bytes                           PRISM_NAMESPACE(secret_key_from_bytes)
#define secret_key_to_bytes                             PRISM_NAMESPACE(secret_key_to_bytes)

// Namespacing symbols exported from encode_verification.c:
#undef public_key_from_bytes
#undef public_key_to_bytes
#undef signature_from_bytes
#undef signature_to_bytes

#define public_key_from_bytes                           PRISM_NAMESPACE(public_key_from_bytes)
#define public_key_to_bytes                             PRISM_NAMESPACE(public_key_to_bytes)
#define signature_from_bytes                            PRISM_NAMESPACE(signature_from_bytes)
#define signature_to_bytes                              PRISM_NAMESPACE(signature_to_bytes)

// Namespacing symbols exported from finit.c:
#undef ibz_mat_2x2_finalize
#undef ibz_mat_2x2_init
#undef ibz_mat_4x4_finalize
#undef ibz_mat_4x4_init
#undef ibz_vec_2_finalize
#undef ibz_vec_2_init
#undef ibz_vec_4_finalize
#undef ibz_vec_4_init
#undef quat_alg_elem_finalize
#undef quat_alg_elem_init
#undef quat_alg_finalize
#undef quat_alg_init_set
#undef quat_lattice_finalize
#undef quat_lattice_init
#undef quat_left_ideal_finalize
#undef quat_left_ideal_init

#define ibz_mat_2x2_finalize                            PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_finalize)
#define ibz_mat_2x2_init                                PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_init)
#define ibz_mat_4x4_finalize                            PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_finalize)
#define ibz_mat_4x4_init                                PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_init)
#define ibz_vec_2_finalize                              PRISM_NAMESPACE_GENERIC(ibz_vec_2_finalize)
#define ibz_vec_2_init                                  PRISM_NAMESPACE_GENERIC(ibz_vec_2_init)
#define ibz_vec_4_finalize                              PRISM_NAMESPACE_GENERIC(ibz_vec_4_finalize)
#define ibz_vec_4_init                                  PRISM_NAMESPACE_GENERIC(ibz_vec_4_init)
#define quat_alg_elem_finalize                          PRISM_NAMESPACE_GENERIC(quat_alg_elem_finalize)
#define quat_alg_elem_init                              PRISM_NAMESPACE_GENERIC(quat_alg_elem_init)
#define quat_alg_finalize                               PRISM_NAMESPACE_GENERIC(quat_alg_finalize)
#define quat_alg_init_set                               PRISM_NAMESPACE_GENERIC(quat_alg_init_set)
#define quat_lattice_finalize                           PRISM_NAMESPACE_GENERIC(quat_lattice_finalize)
#define quat_lattice_init                               PRISM_NAMESPACE_GENERIC(quat_lattice_init)
#define quat_left_ideal_finalize                        PRISM_NAMESPACE_GENERIC(quat_left_ideal_finalize)
#define quat_left_ideal_init                            PRISM_NAMESPACE_GENERIC(quat_left_ideal_init)

// Namespacing symbols exported from fp.c:
#undef fp_select

#define fp_select                                       PRISM_NAMESPACE(fp_select)

// Namespacing symbols exported from fp.c, fp_p27500_64.c, fp_p5248_64.c, fp_p65376_64.c:
#undef fp_exp3div4
#undef fp_inv
#undef fp_is_square
#undef fp_sqrt

#define fp_exp3div4                                     PRISM_NAMESPACE(fp_exp3div4)
#define fp_inv                                          PRISM_NAMESPACE(fp_inv)
#define fp_is_square                                    PRISM_NAMESPACE(fp_is_square)
#define fp_sqrt                                         PRISM_NAMESPACE(fp_sqrt)

// Namespacing symbols exported from fp2.c:
#undef fp2_add
#undef fp2_add_one
#undef fp2_batched_inv
#undef fp2_copy
#undef fp2_cswap
#undef fp2_decode
#undef fp2_encode
#undef fp2_half
#undef fp2_inv
#undef fp2_is_equal
#undef fp2_is_one
#undef fp2_is_square
#undef fp2_is_zero
#undef fp2_mul
#undef fp2_mul_small
#undef fp2_neg
#undef fp2_pow_vartime
#undef fp2_print
#undef fp2_select
#undef fp2_set_one
#undef fp2_set_small
#undef fp2_set_zero
#undef fp2_sqr
#undef fp2_sqrt
#undef fp2_sqrt_verify
#undef fp2_sub

#define fp2_add                                         PRISM_NAMESPACE(fp2_add)
#define fp2_add_one                                     PRISM_NAMESPACE(fp2_add_one)
#define fp2_batched_inv                                 PRISM_NAMESPACE(fp2_batched_inv)
#define fp2_copy                                        PRISM_NAMESPACE(fp2_copy)
#define fp2_cswap                                       PRISM_NAMESPACE(fp2_cswap)
#define fp2_decode                                      PRISM_NAMESPACE(fp2_decode)
#define fp2_encode                                      PRISM_NAMESPACE(fp2_encode)
#define fp2_half                                        PRISM_NAMESPACE(fp2_half)
#define fp2_inv                                         PRISM_NAMESPACE(fp2_inv)
#define fp2_is_equal                                    PRISM_NAMESPACE(fp2_is_equal)
#define fp2_is_one                                      PRISM_NAMESPACE(fp2_is_one)
#define fp2_is_square                                   PRISM_NAMESPACE(fp2_is_square)
#define fp2_is_zero                                     PRISM_NAMESPACE(fp2_is_zero)
#define fp2_mul                                         PRISM_NAMESPACE(fp2_mul)
#define fp2_mul_small                                   PRISM_NAMESPACE(fp2_mul_small)
#define fp2_neg                                         PRISM_NAMESPACE(fp2_neg)
#define fp2_pow_vartime                                 PRISM_NAMESPACE(fp2_pow_vartime)
#define fp2_print                                       PRISM_NAMESPACE(fp2_print)
#define fp2_select                                      PRISM_NAMESPACE(fp2_select)
#define fp2_set_one                                     PRISM_NAMESPACE(fp2_set_one)
#define fp2_set_small                                   PRISM_NAMESPACE(fp2_set_small)
#define fp2_set_zero                                    PRISM_NAMESPACE(fp2_set_zero)
#define fp2_sqr                                         PRISM_NAMESPACE(fp2_sqr)
#define fp2_sqrt                                        PRISM_NAMESPACE(fp2_sqrt)
#define fp2_sqrt_verify                                 PRISM_NAMESPACE(fp2_sqrt_verify)
#define fp2_sub                                         PRISM_NAMESPACE(fp2_sub)

// Namespacing symbols exported from fp_p27500_64.c, fp_p5248_64.c, fp_p65376_64.c:
#undef fp_copy
#undef fp_cswap
#undef fp_decode
#undef fp_decode_reduce
#undef fp_div3
#undef fp_encode
#undef fp_half
#undef fp_is_equal
#undef fp_is_zero
#undef fp_mul_small
#undef fp_neg
#undef fp_set_one
#undef fp_set_small
#undef fp_set_zero

#define fp_copy                                         PRISM_NAMESPACE(fp_copy)
#define fp_cswap                                        PRISM_NAMESPACE(fp_cswap)
#define fp_decode                                       PRISM_NAMESPACE(fp_decode)
#define fp_decode_reduce                                PRISM_NAMESPACE(fp_decode_reduce)
#define fp_div3                                         PRISM_NAMESPACE(fp_div3)
#define fp_encode                                       PRISM_NAMESPACE(fp_encode)
#define fp_half                                         PRISM_NAMESPACE(fp_half)
#define fp_is_equal                                     PRISM_NAMESPACE(fp_is_equal)
#define fp_is_zero                                      PRISM_NAMESPACE(fp_is_zero)
#define fp_mul_small                                    PRISM_NAMESPACE(fp_mul_small)
#define fp_neg                                          PRISM_NAMESPACE(fp_neg)
#define fp_set_one                                      PRISM_NAMESPACE(fp_set_one)
#define fp_set_small                                    PRISM_NAMESPACE(fp_set_small)
#define fp_set_zero                                     PRISM_NAMESPACE(fp_set_zero)

// Namespacing symbols exported from fp_p27500_64.c, fp_p5248_64.c, fp_p65376_64.c, gf27500.c, gf5248.c, gf65376.c:
#undef fp_add
#undef fp_mul
#undef fp_sqr
#undef fp_sub

#define fp_add                                          PRISM_NAMESPACE(fp_add)
#define fp_mul                                          PRISM_NAMESPACE(fp_mul)
#define fp_sqr                                          PRISM_NAMESPACE(fp_sqr)
#define fp_sub                                          PRISM_NAMESPACE(fp_sub)

// Namespacing symbols exported from gf27500.c:
#undef gf27500_decode
#undef gf27500_decode_reduce
#undef gf27500_div
#undef gf27500_div3
#undef gf27500_encode
#undef gf27500_invert
#undef gf27500_legendre
#undef gf27500_sqrt

#define gf27500_decode                                  PRISM_NAMESPACE(gf27500_decode)
#define gf27500_decode_reduce                           PRISM_NAMESPACE(gf27500_decode_reduce)
#define gf27500_div                                     PRISM_NAMESPACE(gf27500_div)
#define gf27500_div3                                    PRISM_NAMESPACE(gf27500_div3)
#define gf27500_encode                                  PRISM_NAMESPACE(gf27500_encode)
#define gf27500_invert                                  PRISM_NAMESPACE(gf27500_invert)
#define gf27500_legendre                                PRISM_NAMESPACE(gf27500_legendre)
#define gf27500_sqrt                                    PRISM_NAMESPACE(gf27500_sqrt)

// Namespacing symbols exported from gf27500.c, gf5248.c, gf65376.c:
#undef fp2_mul_c0
#undef fp2_mul_c1
#undef fp2_sq_c0
#undef fp2_sq_c1

#define fp2_mul_c0                                      PRISM_NAMESPACE(fp2_mul_c0)
#define fp2_mul_c1                                      PRISM_NAMESPACE(fp2_mul_c1)
#define fp2_sq_c0                                       PRISM_NAMESPACE(fp2_sq_c0)
#define fp2_sq_c1                                       PRISM_NAMESPACE(fp2_sq_c1)

// Namespacing symbols exported from gf5248.c:
#undef gf5248_decode
#undef gf5248_decode_reduce
#undef gf5248_div
#undef gf5248_div3
#undef gf5248_encode
#undef gf5248_invert
#undef gf5248_legendre
#undef gf5248_sqrt

#define gf5248_decode                                   PRISM_NAMESPACE(gf5248_decode)
#define gf5248_decode_reduce                            PRISM_NAMESPACE(gf5248_decode_reduce)
#define gf5248_div                                      PRISM_NAMESPACE(gf5248_div)
#define gf5248_div3                                     PRISM_NAMESPACE(gf5248_div3)
#define gf5248_encode                                   PRISM_NAMESPACE(gf5248_encode)
#define gf5248_invert                                   PRISM_NAMESPACE(gf5248_invert)
#define gf5248_legendre                                 PRISM_NAMESPACE(gf5248_legendre)
#define gf5248_sqrt                                     PRISM_NAMESPACE(gf5248_sqrt)

// Namespacing symbols exported from gf65376.c:
#undef gf65376_decode
#undef gf65376_decode_reduce
#undef gf65376_div
#undef gf65376_div3
#undef gf65376_encode
#undef gf65376_invert
#undef gf65376_legendre
#undef gf65376_sqrt

#define gf65376_decode                                  PRISM_NAMESPACE(gf65376_decode)
#define gf65376_decode_reduce                           PRISM_NAMESPACE(gf65376_decode_reduce)
#define gf65376_div                                     PRISM_NAMESPACE(gf65376_div)
#define gf65376_div3                                    PRISM_NAMESPACE(gf65376_div3)
#define gf65376_encode                                  PRISM_NAMESPACE(gf65376_encode)
#define gf65376_invert                                  PRISM_NAMESPACE(gf65376_invert)
#define gf65376_legendre                                PRISM_NAMESPACE(gf65376_legendre)
#define gf65376_sqrt                                    PRISM_NAMESPACE(gf65376_sqrt)

// Namespacing symbols exported from hd.c:
#undef add_couple_jac_points
#undef copy_bases_to_kernel
#undef couple_jac_to_xz
#undef double_couple_jac_point
#undef double_couple_jac_point_iter
#undef double_couple_point
#undef double_couple_point_iter

#define add_couple_jac_points                           PRISM_NAMESPACE(add_couple_jac_points)
#define copy_bases_to_kernel                            PRISM_NAMESPACE(copy_bases_to_kernel)
#define couple_jac_to_xz                                PRISM_NAMESPACE(couple_jac_to_xz)
#define double_couple_jac_point                         PRISM_NAMESPACE(double_couple_jac_point)
#define double_couple_jac_point_iter                    PRISM_NAMESPACE(double_couple_jac_point_iter)
#define double_couple_point                             PRISM_NAMESPACE(double_couple_point)
#define double_couple_point_iter                        PRISM_NAMESPACE(double_couple_point_iter)

// Namespacing symbols exported from hnf.c:
#undef ibz_mat_4x4_is_hnf
#undef ibz_mat_4xn_hnf_mod_core
#undef ibz_vec_4_copy_mod
#undef ibz_vec_4_linear_combination_mod
#undef ibz_vec_4_scalar_mul_mod

#define ibz_mat_4x4_is_hnf                              PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_is_hnf)
#define ibz_mat_4xn_hnf_mod_core                        PRISM_NAMESPACE_GENERIC(ibz_mat_4xn_hnf_mod_core)
#define ibz_vec_4_copy_mod                              PRISM_NAMESPACE_GENERIC(ibz_vec_4_copy_mod)
#define ibz_vec_4_linear_combination_mod                PRISM_NAMESPACE_GENERIC(ibz_vec_4_linear_combination_mod)
#define ibz_vec_4_scalar_mul_mod                        PRISM_NAMESPACE_GENERIC(ibz_vec_4_scalar_mul_mod)

// Namespacing symbols exported from hnf_internal.c:
#undef ibz_centered_mod
#undef ibz_conditional_assign
#undef ibz_mod_not_zero
#undef ibz_xgcd_with_u_not_0

#define ibz_centered_mod                                PRISM_NAMESPACE_GENERIC(ibz_centered_mod)
#define ibz_conditional_assign                          PRISM_NAMESPACE_GENERIC(ibz_conditional_assign)
#define ibz_mod_not_zero                                PRISM_NAMESPACE_GENERIC(ibz_mod_not_zero)
#define ibz_xgcd_with_u_not_0                           PRISM_NAMESPACE_GENERIC(ibz_xgcd_with_u_not_0)

// Namespacing symbols exported from ibz_division.c:
#undef ibz_xgcd

#define ibz_xgcd                                        PRISM_NAMESPACE_GENERIC(ibz_xgcd)

// Namespacing symbols exported from id2iso.c:
#undef change_of_basis_matrix_tate
#undef change_of_basis_matrix_tate_invert
#undef ec_biscalar_mul_ibz_vec
#undef endomorphism_application_even_basis
#undef id2iso_ideal_to_kernel_dlogs_even
#undef id2iso_kernel_dlogs_to_ideal_even
#undef matrix_application_even_basis

#define change_of_basis_matrix_tate                     PRISM_NAMESPACE(change_of_basis_matrix_tate)
#define change_of_basis_matrix_tate_invert              PRISM_NAMESPACE(change_of_basis_matrix_tate_invert)
#define ec_biscalar_mul_ibz_vec                         PRISM_NAMESPACE(ec_biscalar_mul_ibz_vec)
#define endomorphism_application_even_basis             PRISM_NAMESPACE(endomorphism_application_even_basis)
#define id2iso_ideal_to_kernel_dlogs_even               PRISM_NAMESPACE(id2iso_ideal_to_kernel_dlogs_even)
#define id2iso_kernel_dlogs_to_ideal_even               PRISM_NAMESPACE(id2iso_kernel_dlogs_to_ideal_even)
#define matrix_application_even_basis                   PRISM_NAMESPACE(matrix_application_even_basis)

// Namespacing symbols exported from ideal.c:
#undef quat_lideal_add
#undef quat_lideal_class_gram
#undef quat_lideal_conjugate_without_hnf
#undef quat_lideal_copy
#undef quat_lideal_create
#undef quat_lideal_create_principal
#undef quat_lideal_equals
#undef quat_lideal_generator
#undef quat_lideal_inter
#undef quat_lideal_inverse_lattice_without_hnf
#undef quat_lideal_mul
#undef quat_lideal_norm
#undef quat_lideal_right_order
#undef quat_lideal_right_transporter
#undef quat_order_discriminant
#undef quat_order_is_maximal

#define quat_lideal_add                                 PRISM_NAMESPACE_GENERIC(quat_lideal_add)
#define quat_lideal_class_gram                          PRISM_NAMESPACE_GENERIC(quat_lideal_class_gram)
#define quat_lideal_conjugate_without_hnf               PRISM_NAMESPACE_GENERIC(quat_lideal_conjugate_without_hnf)
#define quat_lideal_copy                                PRISM_NAMESPACE_GENERIC(quat_lideal_copy)
#define quat_lideal_create                              PRISM_NAMESPACE_GENERIC(quat_lideal_create)
#define quat_lideal_create_principal                    PRISM_NAMESPACE_GENERIC(quat_lideal_create_principal)
#define quat_lideal_equals                              PRISM_NAMESPACE_GENERIC(quat_lideal_equals)
#define quat_lideal_generator                           PRISM_NAMESPACE_GENERIC(quat_lideal_generator)
#define quat_lideal_inter                               PRISM_NAMESPACE_GENERIC(quat_lideal_inter)
#define quat_lideal_inverse_lattice_without_hnf         PRISM_NAMESPACE_GENERIC(quat_lideal_inverse_lattice_without_hnf)
#define quat_lideal_mul                                 PRISM_NAMESPACE_GENERIC(quat_lideal_mul)
#define quat_lideal_norm                                PRISM_NAMESPACE_GENERIC(quat_lideal_norm)
#define quat_lideal_right_order                         PRISM_NAMESPACE_GENERIC(quat_lideal_right_order)
#define quat_lideal_right_transporter                   PRISM_NAMESPACE_GENERIC(quat_lideal_right_transporter)
#define quat_order_discriminant                         PRISM_NAMESPACE_GENERIC(quat_order_discriminant)
#define quat_order_is_maximal                           PRISM_NAMESPACE_GENERIC(quat_order_is_maximal)

// Namespacing symbols exported from intbig.c:
#undef ibz_abs
#undef ibz_add
#undef ibz_bitsize
#undef ibz_cmp
#undef ibz_cmp_int32
#undef ibz_convert_to_str
#undef ibz_copy
#undef ibz_copy_digits
#undef ibz_div
#undef ibz_div_2exp
#undef ibz_div_floor
#undef ibz_divides
#undef ibz_finalize
#undef ibz_gcd
#undef ibz_get
#undef ibz_init
#undef ibz_invmod
#undef ibz_is_even
#undef ibz_is_odd
#undef ibz_is_one
#undef ibz_is_zero
#undef ibz_legendre
#undef ibz_mod
#undef ibz_mod_ui
#undef ibz_mul
#undef ibz_neg
#undef ibz_pow
#undef ibz_pow_mod
#undef ibz_print
#undef ibz_probab_prime
#undef ibz_rand_interval
#undef ibz_rand_interval_bits
#undef ibz_rand_interval_i
#undef ibz_rand_interval_minm_m
#undef ibz_set
#undef ibz_set_from_str
#undef ibz_size_in_base
#undef ibz_sqrt
#undef ibz_sqrt_floor
#undef ibz_sqrt_mod_p
#undef ibz_sub
#undef ibz_swap
#undef ibz_to_digits
#undef ibz_two_adic

#define ibz_abs                                         PRISM_NAMESPACE_GENERIC(ibz_abs)
#define ibz_add                                         PRISM_NAMESPACE_GENERIC(ibz_add)
#define ibz_bitsize                                     PRISM_NAMESPACE_GENERIC(ibz_bitsize)
#define ibz_cmp                                         PRISM_NAMESPACE_GENERIC(ibz_cmp)
#define ibz_cmp_int32                                   PRISM_NAMESPACE_GENERIC(ibz_cmp_int32)
#define ibz_convert_to_str                              PRISM_NAMESPACE_GENERIC(ibz_convert_to_str)
#define ibz_copy                                        PRISM_NAMESPACE_GENERIC(ibz_copy)
#define ibz_copy_digits                                 PRISM_NAMESPACE_GENERIC(ibz_copy_digits)
#define ibz_div                                         PRISM_NAMESPACE_GENERIC(ibz_div)
#define ibz_div_2exp                                    PRISM_NAMESPACE_GENERIC(ibz_div_2exp)
#define ibz_div_floor                                   PRISM_NAMESPACE_GENERIC(ibz_div_floor)
#define ibz_divides                                     PRISM_NAMESPACE_GENERIC(ibz_divides)
#define ibz_finalize                                    PRISM_NAMESPACE_GENERIC(ibz_finalize)
#define ibz_gcd                                         PRISM_NAMESPACE_GENERIC(ibz_gcd)
#define ibz_get                                         PRISM_NAMESPACE_GENERIC(ibz_get)
#define ibz_init                                        PRISM_NAMESPACE_GENERIC(ibz_init)
#define ibz_invmod                                      PRISM_NAMESPACE_GENERIC(ibz_invmod)
#define ibz_is_even                                     PRISM_NAMESPACE_GENERIC(ibz_is_even)
#define ibz_is_odd                                      PRISM_NAMESPACE_GENERIC(ibz_is_odd)
#define ibz_is_one                                      PRISM_NAMESPACE_GENERIC(ibz_is_one)
#define ibz_is_zero                                     PRISM_NAMESPACE_GENERIC(ibz_is_zero)
#define ibz_legendre                                    PRISM_NAMESPACE_GENERIC(ibz_legendre)
#define ibz_mod                                         PRISM_NAMESPACE_GENERIC(ibz_mod)
#define ibz_mod_ui                                      PRISM_NAMESPACE_GENERIC(ibz_mod_ui)
#define ibz_mul                                         PRISM_NAMESPACE_GENERIC(ibz_mul)
#define ibz_neg                                         PRISM_NAMESPACE_GENERIC(ibz_neg)
#define ibz_pow                                         PRISM_NAMESPACE_GENERIC(ibz_pow)
#define ibz_pow_mod                                     PRISM_NAMESPACE_GENERIC(ibz_pow_mod)
#define ibz_print                                       PRISM_NAMESPACE_GENERIC(ibz_print)
#define ibz_probab_prime                                PRISM_NAMESPACE_GENERIC(ibz_probab_prime)
#define ibz_rand_interval                               PRISM_NAMESPACE_GENERIC(ibz_rand_interval)
#define ibz_rand_interval_bits                          PRISM_NAMESPACE_GENERIC(ibz_rand_interval_bits)
#define ibz_rand_interval_i                             PRISM_NAMESPACE_GENERIC(ibz_rand_interval_i)
#define ibz_rand_interval_minm_m                        PRISM_NAMESPACE_GENERIC(ibz_rand_interval_minm_m)
#define ibz_set                                         PRISM_NAMESPACE_GENERIC(ibz_set)
#define ibz_set_from_str                                PRISM_NAMESPACE_GENERIC(ibz_set_from_str)
#define ibz_size_in_base                                PRISM_NAMESPACE_GENERIC(ibz_size_in_base)
#define ibz_sqrt                                        PRISM_NAMESPACE_GENERIC(ibz_sqrt)
#define ibz_sqrt_floor                                  PRISM_NAMESPACE_GENERIC(ibz_sqrt_floor)
#define ibz_sqrt_mod_p                                  PRISM_NAMESPACE_GENERIC(ibz_sqrt_mod_p)
#define ibz_sub                                         PRISM_NAMESPACE_GENERIC(ibz_sub)
#define ibz_swap                                        PRISM_NAMESPACE_GENERIC(ibz_swap)
#define ibz_to_digits                                   PRISM_NAMESPACE_GENERIC(ibz_to_digits)
#define ibz_two_adic                                    PRISM_NAMESPACE_GENERIC(ibz_two_adic)

// Namespacing symbols exported from integers.c:
#undef ibz_cornacchia_prime
#undef ibz_generate_random_prime

#define ibz_cornacchia_prime                            PRISM_NAMESPACE_GENERIC(ibz_cornacchia_prime)
#define ibz_generate_random_prime                       PRISM_NAMESPACE_GENERIC(ibz_generate_random_prime)

// Namespacing symbols exported from isog_chains.c:
#undef ec_eval_even
#undef ec_eval_small_chain
#undef ec_iso_eval
#undef ec_isomorphism

#define ec_eval_even                                    PRISM_NAMESPACE(ec_eval_even)
#define ec_eval_small_chain                             PRISM_NAMESPACE(ec_eval_small_chain)
#define ec_iso_eval                                     PRISM_NAMESPACE(ec_iso_eval)
#define ec_isomorphism                                  PRISM_NAMESPACE(ec_isomorphism)

// Namespacing symbols exported from keygen.c:
#undef protocols_keygen
#undef secret_key_finalize
#undef secret_key_init

#define protocols_keygen                                PRISM_NAMESPACE(protocols_keygen)
#define secret_key_finalize                             PRISM_NAMESPACE(secret_key_finalize)
#define secret_key_init                                 PRISM_NAMESPACE(secret_key_init)

// Namespacing symbols exported from l2.c:
#undef quat_lattice_lll
#undef quat_lll_core

#define quat_lattice_lll                                PRISM_NAMESPACE_GENERIC(quat_lattice_lll)
#define quat_lll_core                                   PRISM_NAMESPACE_GENERIC(quat_lll_core)

// Namespacing symbols exported from lat_ball.c:
#undef quat_lattice_bound_parallelogram
#undef quat_lattice_sample_from_ball

#define quat_lattice_bound_parallelogram                PRISM_NAMESPACE_GENERIC(quat_lattice_bound_parallelogram)
#define quat_lattice_sample_from_ball                   PRISM_NAMESPACE_GENERIC(quat_lattice_sample_from_ball)

// Namespacing symbols exported from lattice.c:
#undef quat_lattice_add
#undef quat_lattice_alg_elem_mul
#undef quat_lattice_conjugate_without_hnf
#undef quat_lattice_contains
#undef quat_lattice_dual_without_hnf
#undef quat_lattice_equal
#undef quat_lattice_gram
#undef quat_lattice_hnf
#undef quat_lattice_inclusion
#undef quat_lattice_index
#undef quat_lattice_intersect
#undef quat_lattice_mat_alg_coord_mul_without_hnf
#undef quat_lattice_mul
#undef quat_lattice_reduce_denom

#define quat_lattice_add                                PRISM_NAMESPACE_GENERIC(quat_lattice_add)
#define quat_lattice_alg_elem_mul                       PRISM_NAMESPACE_GENERIC(quat_lattice_alg_elem_mul)
#define quat_lattice_conjugate_without_hnf              PRISM_NAMESPACE_GENERIC(quat_lattice_conjugate_without_hnf)
#define quat_lattice_contains                           PRISM_NAMESPACE_GENERIC(quat_lattice_contains)
#define quat_lattice_dual_without_hnf                   PRISM_NAMESPACE_GENERIC(quat_lattice_dual_without_hnf)
#define quat_lattice_equal                              PRISM_NAMESPACE_GENERIC(quat_lattice_equal)
#define quat_lattice_gram                               PRISM_NAMESPACE_GENERIC(quat_lattice_gram)
#define quat_lattice_hnf                                PRISM_NAMESPACE_GENERIC(quat_lattice_hnf)
#define quat_lattice_inclusion                          PRISM_NAMESPACE_GENERIC(quat_lattice_inclusion)
#define quat_lattice_index                              PRISM_NAMESPACE_GENERIC(quat_lattice_index)
#define quat_lattice_intersect                          PRISM_NAMESPACE_GENERIC(quat_lattice_intersect)
#define quat_lattice_mat_alg_coord_mul_without_hnf      PRISM_NAMESPACE_GENERIC(quat_lattice_mat_alg_coord_mul_without_hnf)
#define quat_lattice_mul                                PRISM_NAMESPACE_GENERIC(quat_lattice_mul)
#define quat_lattice_reduce_denom                       PRISM_NAMESPACE_GENERIC(quat_lattice_reduce_denom)

// Namespacing symbols exported from lll_applications.c:
#undef quat_lideal_lideal_mul_reduced
#undef quat_lideal_prime_norm_reduced_equivalent
#undef quat_lideal_reduce_basis

#define quat_lideal_lideal_mul_reduced                  PRISM_NAMESPACE_GENERIC(quat_lideal_lideal_mul_reduced)
#define quat_lideal_prime_norm_reduced_equivalent       PRISM_NAMESPACE_GENERIC(quat_lideal_prime_norm_reduced_equivalent)
#define quat_lideal_reduce_basis                        PRISM_NAMESPACE_GENERIC(quat_lideal_reduce_basis)

// Namespacing symbols exported from lll_verification.c:
#undef ibq_vec_4_copy_ibz
#undef quat_lll_bilinear
#undef quat_lll_gram_schmidt_transposed_with_ibq
#undef quat_lll_set_ibq_parameters
#undef quat_lll_verify

#define ibq_vec_4_copy_ibz                              PRISM_NAMESPACE_GENERIC(ibq_vec_4_copy_ibz)
#define quat_lll_bilinear                               PRISM_NAMESPACE_GENERIC(quat_lll_bilinear)
#define quat_lll_gram_schmidt_transposed_with_ibq       PRISM_NAMESPACE_GENERIC(quat_lll_gram_schmidt_transposed_with_ibq)
#define quat_lll_set_ibq_parameters                     PRISM_NAMESPACE_GENERIC(quat_lll_set_ibq_parameters)
#define quat_lll_verify                                 PRISM_NAMESPACE_GENERIC(quat_lll_verify)

// Namespacing symbols exported from mem.c:
#undef prism_secure_clear
#undef prism_secure_free

#define prism_secure_clear                            PRISM_NAMESPACE_GENERIC(prism_secure_clear)
#define prism_secure_free                             PRISM_NAMESPACE_GENERIC(prism_secure_free)

// Namespacing symbols exported from mp.c:
#undef MUL
#undef mp_add
#undef mp_compare
#undef mp_copy
#undef mp_inv_2e
#undef mp_invert_matrix
#undef mp_is_one
#undef mp_is_zero
#undef mp_mod_2exp
#undef mp_mul
#undef mp_mul2
#undef mp_neg
#undef mp_print
#undef mp_shiftl
#undef mp_shiftr
#undef mp_sub
#undef multiple_mp_shiftl
#undef select_ct
#undef swap_ct

#define MUL                                             PRISM_NAMESPACE_GENERIC(MUL)
#define mp_add                                          PRISM_NAMESPACE_GENERIC(mp_add)
#define mp_compare                                      PRISM_NAMESPACE_GENERIC(mp_compare)
#define mp_copy                                         PRISM_NAMESPACE_GENERIC(mp_copy)
#define mp_inv_2e                                       PRISM_NAMESPACE_GENERIC(mp_inv_2e)
#define mp_invert_matrix                                PRISM_NAMESPACE_GENERIC(mp_invert_matrix)
#define mp_is_one                                       PRISM_NAMESPACE_GENERIC(mp_is_one)
#define mp_is_zero                                      PRISM_NAMESPACE_GENERIC(mp_is_zero)
#define mp_mod_2exp                                     PRISM_NAMESPACE_GENERIC(mp_mod_2exp)
#define mp_mul                                          PRISM_NAMESPACE_GENERIC(mp_mul)
#define mp_mul2                                         PRISM_NAMESPACE_GENERIC(mp_mul2)
#define mp_neg                                          PRISM_NAMESPACE_GENERIC(mp_neg)
#define mp_print                                        PRISM_NAMESPACE_GENERIC(mp_print)
#define mp_shiftl                                       PRISM_NAMESPACE_GENERIC(mp_shiftl)
#define mp_shiftr                                       PRISM_NAMESPACE_GENERIC(mp_shiftr)
#define mp_sub                                          PRISM_NAMESPACE_GENERIC(mp_sub)
#define multiple_mp_shiftl                              PRISM_NAMESPACE_GENERIC(multiple_mp_shiftl)
#define select_ct                                       PRISM_NAMESPACE_GENERIC(select_ct)
#define swap_ct                                         PRISM_NAMESPACE_GENERIC(swap_ct)

// Namespacing symbols exported from normeq.c:
#undef quat_change_to_O0_basis
#undef quat_lattice_O0_set
#undef quat_lattice_O0_set_extremal
#undef quat_order_elem_create
#undef quat_represent_integer
#undef quat_sampling_random_ideal_O0_given_norm

#define quat_change_to_O0_basis                         PRISM_NAMESPACE_GENERIC(quat_change_to_O0_basis)
#define quat_lattice_O0_set                             PRISM_NAMESPACE_GENERIC(quat_lattice_O0_set)
#define quat_lattice_O0_set_extremal                    PRISM_NAMESPACE_GENERIC(quat_lattice_O0_set_extremal)
#define quat_order_elem_create                          PRISM_NAMESPACE_GENERIC(quat_order_elem_create)
#define quat_represent_integer                          PRISM_NAMESPACE_GENERIC(quat_represent_integer)
#define quat_sampling_random_ideal_O0_given_norm        PRISM_NAMESPACE_GENERIC(quat_sampling_random_ideal_O0_given_norm)

// Namespacing symbols exported from printer.c:
#undef ibz_mat_2x2_print
#undef ibz_mat_4x4_print
#undef ibz_vec_2_print
#undef ibz_vec_4_print
#undef quat_alg_elem_print
#undef quat_alg_print
#undef quat_lattice_print
#undef quat_left_ideal_print

#define ibz_mat_2x2_print                               PRISM_NAMESPACE_GENERIC(ibz_mat_2x2_print)
#define ibz_mat_4x4_print                               PRISM_NAMESPACE_GENERIC(ibz_mat_4x4_print)
#define ibz_vec_2_print                                 PRISM_NAMESPACE_GENERIC(ibz_vec_2_print)
#define ibz_vec_4_print                                 PRISM_NAMESPACE_GENERIC(ibz_vec_4_print)
#define quat_alg_elem_print                             PRISM_NAMESPACE_GENERIC(quat_alg_elem_print)
#define quat_alg_print                                  PRISM_NAMESPACE_GENERIC(quat_alg_print)
#define quat_lattice_print                              PRISM_NAMESPACE_GENERIC(quat_lattice_print)
#define quat_left_ideal_print                           PRISM_NAMESPACE_GENERIC(quat_left_ideal_print)

// Namespacing symbols exported from random_input_generation.c:
#undef quat_test_input_random_ideal_generation
#undef quat_test_input_random_ideal_lattice_generation
#undef quat_test_input_random_lattice_generation

#define quat_test_input_random_ideal_generation         PRISM_NAMESPACE_GENERIC(quat_test_input_random_ideal_generation)
#define quat_test_input_random_ideal_lattice_generation PRISM_NAMESPACE_GENERIC(quat_test_input_random_ideal_lattice_generation)
#define quat_test_input_random_lattice_generation       PRISM_NAMESPACE_GENERIC(quat_test_input_random_lattice_generation)

// Namespacing symbols exported from rationals.c:
#undef ibq_abs
#undef ibq_add
#undef ibq_cmp
#undef ibq_copy
#undef ibq_finalize
#undef ibq_init
#undef ibq_inv
#undef ibq_is_ibz
#undef ibq_is_one
#undef ibq_is_zero
#undef ibq_mat_4x4_finalize
#undef ibq_mat_4x4_init
#undef ibq_mat_4x4_print
#undef ibq_mul
#undef ibq_neg
#undef ibq_reduce
#undef ibq_set
#undef ibq_sub
#undef ibq_to_ibz
#undef ibq_vec_4_finalize
#undef ibq_vec_4_init
#undef ibq_vec_4_print

#define ibq_abs                                         PRISM_NAMESPACE_GENERIC(ibq_abs)
#define ibq_add                                         PRISM_NAMESPACE_GENERIC(ibq_add)
#define ibq_cmp                                         PRISM_NAMESPACE_GENERIC(ibq_cmp)
#define ibq_copy                                        PRISM_NAMESPACE_GENERIC(ibq_copy)
#define ibq_finalize                                    PRISM_NAMESPACE_GENERIC(ibq_finalize)
#define ibq_init                                        PRISM_NAMESPACE_GENERIC(ibq_init)
#define ibq_inv                                         PRISM_NAMESPACE_GENERIC(ibq_inv)
#define ibq_is_ibz                                      PRISM_NAMESPACE_GENERIC(ibq_is_ibz)
#define ibq_is_one                                      PRISM_NAMESPACE_GENERIC(ibq_is_one)
#define ibq_is_zero                                     PRISM_NAMESPACE_GENERIC(ibq_is_zero)
#define ibq_mat_4x4_finalize                            PRISM_NAMESPACE_GENERIC(ibq_mat_4x4_finalize)
#define ibq_mat_4x4_init                                PRISM_NAMESPACE_GENERIC(ibq_mat_4x4_init)
#define ibq_mat_4x4_print                               PRISM_NAMESPACE_GENERIC(ibq_mat_4x4_print)
#define ibq_mul                                         PRISM_NAMESPACE_GENERIC(ibq_mul)
#define ibq_neg                                         PRISM_NAMESPACE_GENERIC(ibq_neg)
#define ibq_reduce                                      PRISM_NAMESPACE_GENERIC(ibq_reduce)
#define ibq_set                                         PRISM_NAMESPACE_GENERIC(ibq_set)
#define ibq_sub                                         PRISM_NAMESPACE_GENERIC(ibq_sub)
#define ibq_to_ibz                                      PRISM_NAMESPACE_GENERIC(ibq_to_ibz)
#define ibq_vec_4_finalize                              PRISM_NAMESPACE_GENERIC(ibq_vec_4_finalize)
#define ibq_vec_4_init                                  PRISM_NAMESPACE_GENERIC(ibq_vec_4_init)
#define ibq_vec_4_print                                 PRISM_NAMESPACE_GENERIC(ibq_vec_4_print)

// Namespacing symbols exported from sign.c:
#undef protocols_sign

#define protocols_sign                                  PRISM_NAMESPACE(protocols_sign)

// Namespacing symbols exported from prism.c:
#undef prism_keypair
#undef prism_open
#undef prism_sign
#undef prism_verify

#define prism_keypair                                 PRISM_NAMESPACE(prism_keypair)
#define prism_open                                    PRISM_NAMESPACE(prism_open)
#define prism_sign                                    PRISM_NAMESPACE(prism_sign)
#define prism_verify                                  PRISM_NAMESPACE(prism_verify)

// Namespacing symbols exported from theta_isogenies.c:
#undef theta_chain_compute_and_eval
#undef theta_chain_compute_and_eval_randomized
#undef theta_chain_compute_and_eval_verify

#define theta_chain_compute_and_eval                    PRISM_NAMESPACE(theta_chain_compute_and_eval)
#define theta_chain_compute_and_eval_randomized         PRISM_NAMESPACE(theta_chain_compute_and_eval_randomized)
#define theta_chain_compute_and_eval_verify             PRISM_NAMESPACE(theta_chain_compute_and_eval_verify)

// Namespacing symbols exported from theta_structure.c:
#undef double_iter
#undef double_point
#undef is_product_theta_point
#undef theta_precomputation

#define double_iter                                     PRISM_NAMESPACE(double_iter)
#define double_point                                    PRISM_NAMESPACE(double_point)
#define is_product_theta_point                          PRISM_NAMESPACE(is_product_theta_point)
#define theta_precomputation                            PRISM_NAMESPACE(theta_precomputation)

// Namespacing symbols exported from verify.c:
#undef protocols_verify

#define protocols_verify                                PRISM_NAMESPACE(protocols_verify)

// Namespacing symbols exported from xeval.c:
#undef xeval_2
#undef xeval_2_singular
#undef xeval_4

#define xeval_2                                         PRISM_NAMESPACE(xeval_2)
#define xeval_2_singular                                PRISM_NAMESPACE(xeval_2_singular)
#define xeval_4                                         PRISM_NAMESPACE(xeval_4)

// Namespacing symbols exported from xisog.c:
#undef xisog_2
#undef xisog_2_singular
#undef xisog_4

#define xisog_2                                         PRISM_NAMESPACE(xisog_2)
#define xisog_2_singular                                PRISM_NAMESPACE(xisog_2_singular)
#define xisog_4                                         PRISM_NAMESPACE(xisog_4)


#endif


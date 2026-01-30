#ifndef EC_PARAMS_H
#define EC_PARAMS_H

#include <fp.h>

#define TORSION_EVEN_POWER 500
#define A_POWER 320
#define SALT_SIZE 512

// p+1 divided by the power of 2
extern const digit_t p_cofactor_for_2f[1];
#define P_COFACTOR_FOR_2F_BITLENGTH 5

#endif

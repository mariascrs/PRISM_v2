#include <fips202.h>
#include <tutil.h>
#include <mp.h>
#include <encoded_sizes.h>
#include <ec_params.h>
#include <verification.h>
#include <stdint.h>
#include <rng.h>
#include <intbig.h>

#include "prism_namespace.h"
int ibz_probab_prime(const ibz_t *n, int reps);

// to be able to use ibz_t (hack for now)
#include <quaternion.h>

void
public_key_init(public_key_t *pk)
{
    ec_curve_init(&pk->curve);
}

void
public_key_finalize(public_key_t *pk)
{
}

// Helper to get a random uint32 within [0, 2^SALT_SIZE] where SALT_SIZE >=16
uint32_t _get_random_salt(int bits) {
    uint32_t r;
    
    randombytes((unsigned char *)&r, sizeof(uint32_t));

    return r;
}


// compute the challenge (a prime) as the hash of the message
void  
hash_to_challenge(ibz_t *challenge_degree,
                  const unsigned char *message,
                  const public_key_t *pk,
                  size_t length,
                  uint32_t *salt)
            
{   

    int found = 0;
    
    size_t hash_bytes = ((2 * SECURITY_BITS) + 7) / 8;

    unsigned char buf[FP2_ENCODED_BYTES];
    fp2_t j1;
    ec_j_inv(&j1, &pk->curve);
    fp2_encode(buf, &j1);

    ibz_t tmp;
    ibz_init(&tmp);
    ibz_pow(&tmp, &ibz_const_two, A_POWER);

    // Initialize the challenge degree ONCE outside the loop
    ibz_init(challenge_degree);
    // Now we use a salt instead of a counter
    while (!found) {
        digit_t digits[NWORDS_FIELD] = {0};
        shake256incctx ctx;
        shake256_inc_init(&ctx);
        shake256_inc_absorb(&ctx, buf, FP2_ENCODED_BYTES);
        shake256_inc_absorb(&ctx, message, length);
        
        if (*salt == 0xFFFFFFFF) {
            *salt = _get_random_salt(SALT_SIZE); 
        }

        // shake256_inc_absorb(&ctx, (uint8_t *)counter, sizeof(uint32_t)); 
        shake256_inc_absorb(&ctx, (uint8_t *)salt, sizeof(uint32_t));
        shake256_inc_finalize(&ctx);
        shake256_inc_squeeze((void *)digits, hash_bytes, &ctx); 

        ibz_copy_digit_array(challenge_degree, digits);
        ibz_mod(challenge_degree, challenge_degree, &tmp);
        
        found = ibz_probab_prime(challenge_degree, 20);

        if (found) break; // Break if found so that we don't add to the counter, TODO: is there a better way to do this
        
        // (*counter)++;
        if (!found) {
            *salt = 0xFFFFFFFF;
        }
        
    }
}

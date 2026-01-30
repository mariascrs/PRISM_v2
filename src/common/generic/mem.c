// SPDX-License-Identifier: Apache-2.0

#include <mem.h>
#include <string.h>
#include <stdlib.h>

void
prism_secure_free(void *mem, size_t size)
{
    if (mem) {
        typedef void *(*memset_t)(void *, int, size_t);
        static volatile memset_t memset_func = memset;
        memset_func(mem, 0, size);
        free(mem);
    }
}
void
prism_secure_clear(void *mem, size_t size)
{
    typedef void *(*memset_t)(void *, int, size_t);
    static volatile memset_t memset_func = memset;
    memset_func(mem, 0, size);
}

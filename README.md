# PRISM C implementation

This library is a C implementation of [PRISM version 2](https://eprint.iacr.org/2026/443.pdf), namely where the a random salt is added to the message before hashing. 
The code is built upon the [Qlapoti software](https://github.com/KULeuven-COSIC/Qlapoti) (accessed on December 11, 2025), which is itself built from the [SQIsign team's repo](https://www.github.com/SQIsign/the-sqisign) (accessed on April 30, 2025). As such, our software functions similarly to that of SQIsign, and the following instructions are mainly an abridged version of the SQIsign README, available [here](https://github.com/SQISign/the-sqisign/blob/main/README.md).


## Requirements

- CMake (version 3.13 or later)
- C11-compatible compiler
- GMP (version 6.0.0 or later)


## Build

For a generic build
```
$ mkdir -p build
$ cd build
$ cmake -DPRISM_BUILD_TYPE=ref ..
$ make
$ make test
```

An optimized executable with debug code and assertions disabled can be built
replacing the `cmake` command above by
```
cmake -DPRISM_BUILD_TYPE=<ref/broadwell> -DCMAKE_BUILD_TYPE=Release ..
```

## Build options

CMake build options can be specified with `-D<BUILD_OPTION>=<VALUE>`.

### PRISM_BUILD_TYPE

Specifies the build type for which SQIsign is built. The currently supported values are:
- `ref`: builds the plain reference implementation.
- `opt`: builds the optimized implementation which is the same as the reference
  implementation.
- `broadwell`: builds an additional optimized implementation targeting the Intel
  Broadwell architecture (and later). The optimizations are applied to the
  finite field arithmetic.

### CMAKE_BUILD_TYPE

Can be used to specify special build types. The options are:

- `Release`: Builds with optimizations enabled and assertions disabled.
- `Debug`: Builds with debug symbols.
- `ASAN`: Builds with AddressSanitizer memory error detector.
- `MSAN`: Builds with MemorySanitizer detector for uninitialized reads.
- `LSAN`: Builds with LeakSanitizer for run-time memory leak detection.
- `UBSAN`: Builds with UndefinedBehaviorSanitizer for undefined behavior detection.

The default build type uses the flags `-O3 -Wstrict-prototypes -Wno-error=strict-prototypes -fvisibility=hidden -Wno-error=implicit-function-declaration -Wno-error=attributes`. (Notice that assertions remain enabled in this configuration, which harms performance.)

## Test

In the build directory, run `make test` or `ctest`.

The test harness consists of the following units:

- Self-tests: `PRISM_<level>_SELFTEST` - runs random self-tests
  (key generation, signature and verification).
- Sub-library specific unit-tests.

Note that, `ctest` has a default timeout of 1500s. To override the default timeout, run
`ctest --timeout <seconds>`.

## Reproducing Benchmarks

To replicate the benchmarks in the paper, in `build/`
```
$ cmake -DPRISM_BUILD_TYPE=<ref/broadwell> -DCMAKE_BUILD_TYPE=Release ..
$ make
$ apps/benchmark_<level> [--iterations=<iterations>]
```
where `<level>` specifies the PRISM parameter set and `<iterations>` is the
number of iterations used for benchmarking; if the `--iterations` option is
omitted, a default of 10 iterations is used. In the paper, we used `<iterations>` = 10,000.

The benchmarks profile the key generation, signature and verification functions. The results are reported in CPU cycles if available on the host platform, and timing in nanoseconds otherwise.

## Examples

Example code that demonstrates how to use PRISM with the NIST API is available
in `apps/example_nistapi.c`.

## Project Structure

The project structure is identical to that of the SQIsign software.

## Acknowledgements

The reference implementation for finite field arithemtic (i.e., `src/gf/ref`)
was generated using [modarith](https://github.com/mcarrickscott/modarith) by
Michael Scott.

## License

PRISM is licensed under the same license as Qlapoti and SQIsign: Apache-2.0. See [LICENSE](LICENSE) and [NOTICE](NOTICE).

Third party code is used in some files:

- `src/common/aes_c.c`; MIT: "Copyright (c) 2016 Thomas Pornin <pornin@bolet.org>"
- `src/common/fips202.c`: CC0: Copyright (c) 2023, the PQClean team
- `src/common/randombytes_system.c`: MIT: Copyright (c) 2017 Daan Sprenkels <hello@dsprenkels.com>
- `src/common/broadwell/{aes_ni.c, vaes256_key_expansion.S}`: Apache-2.0: Copyright 2019 Amazon.com, Inc.
- `src/common/broadwell/ctr_drbg.c`: ISC: Copyright (c) 2017, Google Inc.
- `src/mini-gmp/mini-gmp.c` and `src/mini-gmp/mini-gmp.h`: LGPLv3: Copyright 1991-1997, 1999-2022 Free Software Foundation, Inc.
- `src/quaternion/ref/generic/dpe.h`: LGPLv3: Copyright (C) 2004-2024 Patrick Pelissier, Paul Zimmermann, LORIA/INRIA
- `apps/PQCgenKAT_sign.c`, `apps/PQCgenKAT_sign_pqm4.c`, `src/common/ref/randombytes_ctrdrbg.c`, `test/test_kat.c`: by NIST (Public Domain)



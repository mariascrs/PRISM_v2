# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13)
project(PRISM VERSION 2.0 LANGUAGES C ASM)

set(PRISM_SO_VERSION "0")
set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(CTest)

option(ENABLE_STRICT "Build with strict compile options." ON)
option(ENABLE_TESTS  "Enable compilation of tests." ON)
option(ENABLE_CT_TESTING  "Enable compilation for constant time testing." OFF)
option(ENABLE_SIGN "Build with sign functionality" ON)
set(GMP_LIBRARY "SYSTEM" CACHE STRING "Which version of GMP to use: SYSTEM, BUILD or MINI")
set(GF_RADIX "AUTO" CACHE STRING "Set the radix for the gf module (currently supported values: 32 or 64), or AUTO.")

if (NOT DEFINED SQISIGN_BUILD_TYPE)
    SET(PRISM_BUILD_TYPE "ref")
endif()

if (${PRISM_BUILD_TYPE} MATCHES "ref")
  add_compile_definitions(PRISM_BUILD_TYPE_REF PRISM_GF_IMPL_REF)
elseif (${PRISM_BUILD_TYPE} MATCHES "opt")
  add_compile_definitions(PRISM_BUILD_TYPE_OPT PRISM_GF_IMPL_REF)
elseif (${PRISM_BUILD_TYPE} MATCHES "broadwell")
  add_compile_definitions(PRISM_BUILD_TYPE_BROADWELL PRISM_GF_IMPL_BROADWELL)
elseif (${PRISM_BUILD_TYPE} MATCHES "arm64crypto")
  add_compile_definitions(PRISM_BUILD_TYPE_ARM64CRYPTO PRISM_GF_IMPL_REF)
endif()

SET(SVARIANT_S "lvl1;lvl3;lvl5")

include(.cmake/flags.cmake)
include(.cmake/sanitizers.cmake)
include(.cmake/target.cmake)
if(ENABLE_SIGN)
	include(.cmake/gmpconfig.cmake)
	add_compile_definitions(ENABLE_SIGN)
endif()

set(BM_BINS "" CACHE INTERNAL "List of benchmark binaries")

set(SELECT_IMPL_TYPE ${PROJECT_SOURCE_DIR}/.cmake/impl_type.cmake)
set(SELECT_PRISM_VARIANT ${PROJECT_SOURCE_DIR}/.cmake/prism_variant.cmake)

set(INC_PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(test)

include(.cmake/bm.cmake)

#if(ENABLE_TESTS)
#    enable_testing()
#    add_subdirectory(test)
#endif()

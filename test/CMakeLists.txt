# SPDX-License-Identifier: Apache-2.0

FOREACH(SVARIANT ${SVARIANT_S})

    string(TOLOWER ${SVARIANT} SVARIANT_LOWER)
    string(TOUPPER ${SVARIANT} SVARIANT_UPPER)

    if (ENABLE_SIGN)

        add_executable(prism_test_scheme_${SVARIANT} test_prism.c)
        target_link_libraries(prism_test_scheme_${SVARIANT} prism_${SVARIANT_LOWER})
        target_include_directories(prism_test_scheme_${SVARIANT} PUBLIC ${PROJECT_SOURCE_DIR}/src/common ${INC_PUBLIC} ${PROJECT_SOURCE_DIR}/src/nistapi/${SVARIANT_LOWER})
        add_test(prism_${SVARIANT}_SELFTEST prism_test_scheme_${SVARIANT})

    endif()

ENDFOREACH()

if (ENABLE_SIGN)

    # Examples with NIST API
    foreach(SVARIANT ${SVARIANT_S})
        string(TOLOWER ${SVARIANT} SVARIANT_LOWER)
        add_executable(example_nistapi_${SVARIANT_LOWER} example_nistapi.c)
        target_link_libraries(example_nistapi_${SVARIANT_LOWER} PRIVATE prism_${SVARIANT_LOWER}_nistapi)
        target_include_directories(example_nistapi_${SVARIANT_LOWER} PRIVATE ../include ../src/${SVARIANT_LOWER})
        target_compile_definitions(example_nistapi_${SVARIANT_LOWER} PUBLIC PRISM_VARIANT=${SVARIANT_LOWER})
        add_test(prism_test_nistapi_${SVARIANT_LOWER} example_nistapi_${SVARIANT_LOWER})
    endforeach()

    # Benchmarking tool
    foreach(SVARIANT ${SVARIANT_S})
        string(TOLOWER ${SVARIANT} SVARIANT_LOWER)
        add_executable(benchmark_${SVARIANT_LOWER} benchmark.c)
        target_link_libraries(benchmark_${SVARIANT_LOWER} PRIVATE prism_${SVARIANT_LOWER}_nistapi)
        target_include_directories(benchmark_${SVARIANT_LOWER} PRIVATE ../include ../src/common/generic/include)
        target_compile_definitions(benchmark_${SVARIANT_LOWER} PUBLIC PRISM_VARIANT=${SVARIANT_LOWER})
    endforeach()

endif()

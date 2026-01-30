add_executable(prism_test_signature_${SVARIANT_LOWER} ${LVLX_DIR}/test/test_signature.c)
target_link_libraries(prism_test_signature_${SVARIANT_LOWER} ${LIB_SIGNATURE_${SVARIANT_UPPER}} ${LIB_VERIFICATION_${SVARIANT_UPPER}} prism_common_test)
target_include_directories(prism_test_signature_${SVARIANT_LOWER} PRIVATE ${INC_PUBLIC} ${INC_COMMON} ${INC_QUATERNION} ${INC_PRECOMP_${SVARIANT_UPPER}} ${INC_GF} ${INC_GF_${SVARIANT_UPPER}} ${INC_EC} ${INC_VERIFICATION} ${INC_SIGNATURE})

add_executable(prism_test_threadsafety_${SVARIANT_LOWER} ${LVLX_DIR}/test/test_threadsafety.c)
target_link_libraries(prism_test_threadsafety_${SVARIANT_LOWER} ${LIB_SIGNATURE_${SVARIANT_UPPER}} ${LIB_VERIFICATION_${SVARIANT_UPPER}} prism_common_test pthread)
target_include_directories(prism_test_threadsafety_${SVARIANT_LOWER} PRIVATE ${INC_PUBLIC} ${INC_COMMON} ${INC_QUATERNION} ${INC_PRECOMP_${SVARIANT_UPPER}} ${INC_GF} ${INC_GF_${SVARIANT_UPPER}} ${INC_EC} ${INC_VERIFICATION} ${INC_SIGNATURE})

add_test(prism_test_signature_${SVARIANT_LOWER} prism_test_signature_${SVARIANT_LOWER} 3)
add_test(prism_test_threadsafety_${SVARIANT_LOWER} prism_test_threadsafety_${SVARIANT_LOWER} 3)

add_custom_command(
  TARGET prism_test_signature_${SVARIANT_LOWER}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND}
  ARGS -E copy $<TARGET_FILE:prism_test_signature_${SVARIANT_LOWER}> ${CMAKE_BINARY_DIR}/test/prism_${SVARIANT_LOWER}
)

add_executable(prism_bench_signature_${SVARIANT_LOWER} ${LVLX_DIR}/test/bench_signature.c)
target_link_libraries(prism_bench_signature_${SVARIANT_LOWER} ${LIB_SIGNATURE_${SVARIANT_UPPER}} ${LIB_VERIFICATION_${SVARIANT_UPPER}} prism_common_sys)
target_include_directories(prism_bench_signature_${SVARIANT_LOWER} PRIVATE ${INC_PUBLIC} ${INC_COMMON} ${INC_QUATERNION} ${INC_PRECOMP_${SVARIANT_UPPER}} ${INC_GF} ${INC_GF_${SVARIANT_UPPER}} ${INC_EC} ${INC_VERIFICATION} ${INC_SIGNATURE})

set(BM_BINS ${BM_BINS} prism_bench_signature_${SVARIANT_LOWER} CACHE INTERNAL "List of benchmark executables")

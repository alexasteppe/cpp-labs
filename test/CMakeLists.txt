if (${LAB} MATCHES "1")
    set(target_name time_test)
    add_executable(
            ${target_name}
            libcsc/libcsc/time.test.cpp
    )
elseif(${LAB} MATCHES "2")
    set(target_name smart_ptr_test)
    add_executable(
            ${target_name}
            libcsc/libcsc/smartPtr.test.cpp
    )
elseif(${LAB} MATCHES "3")
    set(target_name soundex_test)
    add_executable(
            ${target_name}
            libcsc/libcsc/soundex.test.cpp
    )
endif()

include(CompileOptions)
set_compile_options(${target_name})

if (${LAB} MATCHES "1")
    target_link_libraries(
            ${target_name}
            PRIVATE
            time
            gtest_main
    )
elseif(${LAB} MATCHES "2")
    target_link_libraries(
            ${target_name}
            PRIVATE
            smart_ptr
            gtest_main
    )
elseif(${LAB} MATCHES "3")
    target_link_libraries(
            ${target_name}
            PRIVATE
            soundex
            gtest_main
    )
endif()

include(GoogleTest)
gtest_discover_tests(${target_name})
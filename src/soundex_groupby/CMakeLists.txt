set(target_name soundex_groupby)

add_executable(
        ${target_name}
        main.cpp
)

include(CompileOptions)
set_compile_options(${target_name})

target_link_libraries(
        ${target_name}
        PRIVATE
        soundex
        cxxopts
)
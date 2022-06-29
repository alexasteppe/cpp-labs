if (${LAB} MATCHES "1")
    set(target_name time)
    add_library(
            ${target_name} STATIC
            libcsc/time/time.hpp
            libcsc/time/time.cpp
            )
    include(CompileOptions)
    target_include_directories(
            ${target_name}
            PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
    )
endif ()
if (${LAB} MATCHES "2")
    set(target_name smart_ptr)
    add_library(
            ${target_name} INTERFACE
            libcsc/smartptr/SharedPtr.hpp
            libcsc/smartptr/UniquePtr.hpp
    )
    include(CompileOptions)
    target_include_directories(
            ${target_name}
            INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}
    )
endif ()
if (${LAB} MATCHES "3")
    set(target_name soundex)
    add_library(
            ${target_name} STATIC
            libcsc/soundex/soundex.cpp
            libcsc/soundex/soundex.hpp
            libcsc/soundex/soundexUtility.cpp
            libcsc/soundex/soundexUtility.hpp
    )
    include(CompileOptions)
    target_include_directories(
            ${target_name}
            PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
    )
    target_link_libraries(
            ${target_name}
            PRIVATE
            nlohmann_json::nlohmann_json
    )
endif ()

cmake_minimum_required(VERSION 3.14)

include("cmake_files.cmake")

add_library(PML_Lib
    INTERFACE
)

target_include_directories(PML_Lib
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(PML_Lib
    INTERFACE
        cxx_std_20
)
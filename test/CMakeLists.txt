cmake_minimum_required(VERSION 3.14)

add_executable(main
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

target_link_libraries(main
    PRIVATE
        PML_Lib
)
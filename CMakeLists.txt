cmake_minimum_required(VERSION 3.10)
project(tree_algorithm)
set(CMAKE_CXX_STANDARD 17)

include_directories("C:/University/libs/googletest-1.17.0/googletest/include")
link_directories("C:/University/libs/googletest-1.17.0/build/lib")

add_executable(app
    src/first_tree_Borovik.cpp
    include/funkcijas_tree.cpp
)
add_executable(test_tree
    tests/test_tree.cpp
    include/funkcijas_tree.cpp
)
target_link_libraries(test_tree gtest gtest_main pthread)

cmake_minimum_required(VERSION 3.6)
project(bot)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(thirdparty/discpp)

add_executable(main src/main.cpp)

target_include_directories(main PUBLIC include)

file(GLOB_RECURSE source_list src/*.cpp)
target_sources(main PRIVATE ${source_list})

target_link_libraries(main PRIVATE discpp)
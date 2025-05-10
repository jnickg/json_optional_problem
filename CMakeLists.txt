cmake_minimum_required(VERSION 3.10)
project(json_optional_problem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_EXTENSIONS NO)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(cmake/CPM.cmake)
CPMAddPackage(
    NAME nlohmann_json
    GITHUB_REPOSITORY nlohmann/json
    GIT_TAG v3.12.0
    OPTIONS
        "CMAKE_CXX_STANDARD 20"
        "CMAKE_CXX_STANDARD_REQUIRED YES"
)

add_executable(json_optional_problem main.cpp)
target_link_libraries(json_optional_problem PRIVATE nlohmann_json::nlohmann_json)

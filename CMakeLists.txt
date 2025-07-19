cmake_minimum_required(VERSION 3.21)

project(pratt-parser
    VERSION 0.1
    DESCRIPTION "This is horrible implementation of a Pratt parser, and its entire existence is for just one goal: learning"
    HOMEPAGE_URL "https://github.com/karoush1/pratt-parser"
    LANGUAGES C
)

set(CMAKE_C_FLAGS "-Wall -std=c11")
set(CMAKE_C_FLAGS_DEBUG "-g")

include_directories("${PROJECT_SOURCE_DIR}/src")

add_library(tokens STATIC
    ${PROJECT_SOURCE_DIR}/src/tokens.c
    ${PROJECT_SOURCE_DIR}/src/mem_arena.c
)

add_library(pratt STATIC
    ${PROJECT_SOURCE_DIR}/src/pratt.c
    ${PROJECT_SOURCE_DIR}/src/tokens.h
    ${PROJECT_SOURCE_DIR}/src/mem_arena.c
)

add_executable(main
    ${PROJECT_SOURCE_DIR}/src/main.c
    ${PROJECT_SOURCE_DIR}/src/pratt.c
    ${PROJECT_SOURCE_DIR}/src/tokens.c
    ${PROJECT_SOURCE_DIR}/src/log.h
)
target_link_libraries(main pratt tokens)

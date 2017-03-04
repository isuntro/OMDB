cmake_minimum_required(VERSION 3.6)
project(OMDB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        film.c
        film.h
        main.c
        moviedatabase.c
        moviedatabase.h)

add_executable(OMDB ${SOURCE_FILES})
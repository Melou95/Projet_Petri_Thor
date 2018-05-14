cmake_minimum_required(VERSION 3.1.3)

project (Projet_Petri_Thor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp Bacterie.cpp L.cpp S.cpp Env.cpp Case.cpp)

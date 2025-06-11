cmake_minimum_required(VERSION 3.31)
project(Sistema_reserva_de_vuelos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sistema_reserva_de_vuelos main.cpp
        Usuario/Usuario.cpp
        Usuario/Usuario.h
        Vuelo/Vuelo.cpp
        Vuelo/Vuelo.h
        Fecha/Fecha.cpp
        Fecha/Fecha.h)

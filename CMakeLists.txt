cmake_minimum_required(VERSION 3.16)
project(Affin_Cipher_New)

set(CMAKE_CXX_STANDARD 14)

add_executable(Affin_Cipher_New main.cpp AffineCipher.cpp AffineCipher.h FrequencyAnalyzer.cpp FrequencyAnalyzer.h)
cmake_minimum_required(VERSION 3.12)
project(cpp1_assessment)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp1_assessment main.cpp File/FileReader.cpp File/FileReader.h Exception/FileNotOpenedException.cpp Exception/FileNotOpenedException.h File/MonsterFileParser.cpp File/MonsterFileParser.h Monster.cpp Monster.h)
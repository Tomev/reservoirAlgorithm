cmake_minimum_required(VERSION 3.6)
project(reservoirAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp reservoirSamplingAlgorithm.cpp reservoirSamplingAlgorithm.h dataParser.h dataReader.h textDataReader.cpp textDataReader.h textDataParser.cpp textDataParser.h)
add_executable(reservoirAlgorithm ${SOURCE_FILES})
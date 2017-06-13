cmake_minimum_required(VERSION 3.6)
project(reservoirAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp basicReservoirSamplingAlgorithm.cpp basicReservoirSamplingAlgorithm.h dataParser.h dataReader.h textDataReader.cpp textDataReader.h textDataParser.cpp textDataParser.h biasedReservoirSamplingAlgorithm.cpp biasedReservoirSamplingAlgorithm.h reservoirSamplingAlgorithm.h sample.h textDataSample.h textDataSample.cpp)
add_executable(reservoirAlgorithm ${SOURCE_FILES})
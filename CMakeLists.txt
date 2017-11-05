cmake_minimum_required(VERSION 2.6)
project(Neuron)
set(CMAKE-CXX-FLAGS "-03 -W -Wall -std=c++11 -pedantic ")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

add_executable (neuron Neuron.cpp Neuron.hh Neuronmain.cpp Network.cpp Experiment.h Experiment.cpp)
add_executable (neurontest Neuron.hh neurontest.cpp Neuron.cpp Network.cpp)

find_package(Doxygen)
if(DOXYGEN_FOUND)

IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        message(FATAL_ERROR "Doxygen configuration file is needed to build the documentation:
         - ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in not found.
         - Generate one in the project folder with doxygen -g Doxyfile.in")
    ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ELSE(DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation.")
ENDIF(DOXYGEN_FOUND)

target_link_libraries(neurontest gtest gtest_main)
add_test(neurontest neurontest)


cmake_minimum_required(VERSION 2.8)
project(coveralls-cmake)

option(COVERALLS "Turn on coveralls support" OFF)
option(COVERALLS_UPLOAD "Upload the generated coveralls json" ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
	${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake)

if (COVERALLS)
	include(Coveralls)
	coveralls_turn_on_coverage()
endif()

# Create a complicated library!
set(LIB_SRC ${PROJECT_SOURCE_DIR}/complicated.c)
add_library(complicated ${LIB_SRC})
include_directories(${PROJECT_SOURCE_DIR})

# Setup the coveralls target and tell it to gather
# coverage data for all the lib sources.
if (COVERALLS)
	coveralls_setup(
        "${LIB_SRC}" 
        ${COVERALLS_UPLOAD}                 
        "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake")
endif()

# Add a test for the library.
enable_testing()

add_executable(complicated_regress
				${PROJECT_SOURCE_DIR}/test/TEST_complicated.c)

target_link_libraries(complicated_regress complicated)

add_test(complicated ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/complicated_regress)

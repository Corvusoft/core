cmake_minimum_required( VERSION 3.1.0 FATAL_ERROR )

project( "unit test suite" LANGUAGES CXX )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )

include_directories( SYSTEM ${catch_INCLUDE} )

#
# Build
#
add_executable( byte_unit_test_suite ${SOURCE_DIR}/byte.cpp )
target_link_libraries( byte_unit_test_suite ${STATIC_LIBRARY_NAME} )
add_test( byte_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/byte_unit_test_suite )

add_executable( settings_unit_test_suite ${SOURCE_DIR}/settings.cpp )
target_link_libraries( settings_unit_test_suite ${STATIC_LIBRARY_NAME} )
add_test( settings_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_unit_test_suite )

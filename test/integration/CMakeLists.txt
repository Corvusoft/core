cmake_minimum_required( VERSION 3.1.0 FATAL_ERROR )

project( "integration test suite" LANGUAGES CXX )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )

include_directories( SYSTEM ${catch_INCLUDE} )

#
# Build
#
add_executable( settings_destructor_integration_test_suite ${SOURCE_DIR}/settings/destructor.cpp )
target_link_libraries( settings_destructor_integration_test_suite ${STATIC_LIBRARY_NAME} )
add_test( settings_destructor_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_destructor_integration_test_suite )

add_executable( settings_erase_integration_test_suite ${SOURCE_DIR}/settings/erase.cpp )
target_link_libraries( settings_erase_integration_test_suite ${STATIC_LIBRARY_NAME} )
add_test( settings_erase_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_erase_integration_test_suite )

add_executable( settings_get_integration_test_suite ${SOURCE_DIR}/settings/get.cpp )
target_link_libraries( settings_get_integration_test_suite ${STATIC_LIBRARY_NAME} )
add_test( settings_get_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_get_integration_test_suite )

add_executable( settings_has_integration_test_suite ${SOURCE_DIR}/settings/has.cpp )
target_link_libraries( settings_has_integration_test_suite ${STATIC_LIBRARY_NAME} )
add_test( settings_has_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_has_integration_test_suite )

add_executable( settings_set_integration_test_suite ${SOURCE_DIR}/settings/set.cpp )
target_link_libraries( settings_set_integration_test_suite ${STATIC_LIBRARY_NAME} )
add_test( settings_set_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_set_integration_test_suite )

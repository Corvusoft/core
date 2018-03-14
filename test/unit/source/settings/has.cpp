//System Includes
#include <string>

//Project Includes
#include "corvusoft/core/settings.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;

//Project Namespaces
using corvusoft::core::Settings;

//External Namespaces

TEST_CASE( "Test for properties." )
{
    Settings settings;
    REQUIRE( settings.has( "" ) == false );
    REQUIRE( settings.has( "unknown" ) == false );
}

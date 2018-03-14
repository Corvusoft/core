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

TEST_CASE( "Read properties." )
{
    Settings settings;
    REQUIRE( settings.get( "" ) == "" );
    REQUIRE( settings.get( "", "default value" ) == "default value" );
    REQUIRE( settings.get( "unknown" ) == "" );
    REQUIRE( settings.get( "unknonw", "default value for unknown" ) == "default value for unknown" );
}

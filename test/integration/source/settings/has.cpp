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
    settings.set( "string", "value" );
    REQUIRE( settings.has( "string" ) == true );
    REQUIRE( settings.has( "StRiNg" ) == true );
    REQUIRE( settings.has( "STRING" ) == true );
    
    settings.set( "integer", 1 );
    REQUIRE( settings.has( "integer" ) == true );
    REQUIRE( settings.has( "InTeGer" ) == true );
    REQUIRE( settings.has( "INTEGER" ) == true );
    
    settings.set( "float", 3.14159f );
    REQUIRE( settings.has( "float" ) == true );
    REQUIRE( settings.has( "FlOaT" ) == true );
    REQUIRE( settings.has( "FLOAT" ) == true );
    
    settings.set( "double", 27.9769 );
    REQUIRE( settings.has( "double" ) == true );
    REQUIRE( settings.has( "DoUbLe" ) == true );
    REQUIRE( settings.has( "DOUBLE" ) == true );
}

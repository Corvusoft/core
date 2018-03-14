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
    settings.set( "string", "value" );
    REQUIRE( settings.get( "string" ) == "value" );
    REQUIRE( settings.get( "StRiNg" ) == "value" );
    REQUIRE( settings.get( "STRING" ) == "value" );
    
    settings.set( "integer", 1 );
    REQUIRE( settings.get( "integer", 0 ) == 1 );
    REQUIRE( settings.get( "InTeGer", 0 ) == 1 );
    REQUIRE( settings.get( "INTEGER", 0 ) == 1 );
    
    settings.set( "float", 3.14159f );
    REQUIRE( settings.get( "float", 0.0f ) == 3.14159f );
    REQUIRE( settings.get( "FlOaT", 0.0f ) == 3.14159f );
    REQUIRE( settings.get( "FLOAT", 0.0f ) == 3.14159f );
    
    settings.set( "double", 27.9769 );
    REQUIRE( settings.get( "double", 0.0 ) == 27.9769 );
    REQUIRE( settings.get( "DoUbLe", 0.0 ) == 27.9769 );
    REQUIRE( settings.get( "DOUBLE", 0.0 ) == 27.9769 );
}

TEST_CASE( "Assert reading the wrong property type." )
{
    Settings settings;
    settings.set( "integer", 27 );
    REQUIRE( settings.get( "integer" ) == "27" );
    
    settings.set( "string", "value" );
    REQUIRE( settings.get( "string", 0 ) == 0 );
}

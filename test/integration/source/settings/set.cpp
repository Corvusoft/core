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

TEST_CASE( "Write properties." )
{
    Settings settings;
    settings.set( "string", "value 1" );
    REQUIRE( settings.get( "string" ) == "value 1" );
    settings.set( "StRiNg", "value 2" );
    REQUIRE( settings.get( "string" ) == "value 2" );
    settings.set( "STRING", "value 3" );
    REQUIRE( settings.get( "string" ) == "value 3" );
    
    settings.set( "integer", 1 );
    REQUIRE( settings.get( "integer", 0 ) == 1 );
    settings.set( "InTeGer", 2 );
    REQUIRE( settings.get( "integer", 0 ) == 2 );
    settings.set( "INTEGER", 3 );
    REQUIRE( settings.get( "integer", 0 ) == 3 );
    
    settings.set( "float", 1.14159f );
    REQUIRE( settings.get( "float", 0.0f ) == 1.14159f );
    settings.set( "FlOaT", 2.14159f );
    REQUIRE( settings.get( "float", 0.0f ) == 2.14159f );
    settings.set( "FLOAT", 3.14159f );
    REQUIRE( settings.get( "float", 0.0f ) == 3.14159f );
    
    settings.set( "double", 17.9769 );
    REQUIRE( settings.get( "double", 0.0 ) == 17.9769 );
    settings.set( "DoUbLe", 27.9769 );
    REQUIRE( settings.get( "double", 0.0 ) == 27.9769 );
    settings.set( "DOUBLE", 37.9769 );
    REQUIRE( settings.get( "double", 0.0 ) == 37.9769 );
}

TEST_CASE( "Assert writing the wrong property type." )
{
    Settings settings;
    settings.set( "string", "value" );
    REQUIRE_NOTHROW( settings.set( "string", 27 ) );
}

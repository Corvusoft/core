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

TEST_CASE( "Erase properties." )
{
    Settings settings;
    settings.set( "string", "value" );
    REQUIRE_NOTHROW( settings.erase( "string" ) );
    REQUIRE( settings.get( "string" ) == "" );
    
    settings.set( "string", "value" );
    REQUIRE_NOTHROW( settings.erase( "StRiNg" ) );
    REQUIRE( settings.get( "string" ) == "" );
    
    settings.set( "string", "value" );
    REQUIRE_NOTHROW( settings.erase( "STRING" ) );
    REQUIRE( settings.get( "string" ) == "" );
    
    settings.set( "integer", 1 );
    REQUIRE_NOTHROW( settings.erase( "integer" ) );
    REQUIRE( settings.get( "integer", 0 ) == 0 );
    
    settings.set( "integer", 1 );
    REQUIRE_NOTHROW( settings.erase( "InTeGer" ) );
    REQUIRE( settings.get( "integer", 0 ) == 0 );
    
    settings.set( "integer", 1 );
    REQUIRE_NOTHROW( settings.erase( "INTEGER" ) );
    REQUIRE( settings.get( "integer", 0 ) == 0 );
    
    settings.set( "float", 3.14159f );
    REQUIRE_NOTHROW( settings.erase( "float" ) );
    REQUIRE( settings.get( "float", 0.0f ) == 0.0f );
    
    settings.set( "float", 1 );
    REQUIRE_NOTHROW( settings.erase( "FlOaT" ) );
    REQUIRE( settings.get( "float", 0.0f ) == 0.0f );
    
    settings.set( "float", 1 );
    REQUIRE_NOTHROW( settings.erase( "FLOAT" ) );
    REQUIRE( settings.get( "float", 0.0f ) == 0.0f );
    
    settings.set( "double", 27.9769 );
    REQUIRE_NOTHROW( settings.erase( "double" ) );
    REQUIRE( settings.get( "double", 0.0 ) == 0.0 );
    
    settings.set( "double", 27.9769 );
    REQUIRE_NOTHROW( settings.erase( "DoUbLe" ) );
    REQUIRE( settings.get( "double", 0.0 ) == 0.0 );
    
    settings.set( "double", 27.9769 );
    REQUIRE_NOTHROW( settings.erase( "DOUBLE" ) );
    REQUIRE( settings.get( "double", 0.0 ) == 0.0 );
}

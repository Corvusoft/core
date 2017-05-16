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

TEST_CASE( "Setup" )
{
    REQUIRE_NOTHROW( new Settings );
}

TEST_CASE( "Clean-up" )
{
    auto settings = new Settings;
    REQUIRE_NOTHROW( delete settings );
    
    settings = new Settings;
    settings->set( "integer name", 123 );
    settings->set( "float name", 3.4f );
    settings->set( "double name", 3.456 );
    settings->set( "string name", "string value" );
    REQUIRE_NOTHROW( delete settings );
}

TEST_CASE( "Accessing properties" )
{
    Settings settings;
    settings.set( "string name", "string value" );
    REQUIRE( settings.has( "string name" ) == true );
    REQUIRE( settings.get( "string name" ) == "string value" );
    
    settings.set( "integer name", 12345 );
    REQUIRE( settings.has( "integer name" ) == true );
    const int default_integer_value = 0;
    const int integer_value = settings.get( "integer name", default_integer_value );
    REQUIRE( integer_value == 12345 );
    
    settings.set( "float name", 3.14159f );
    REQUIRE( settings.has( "float name" ) == true );
    const float default_float_value = 0.0f;
    const float float_value = settings.get( "float name", default_float_value );
    REQUIRE( float_value == 3.14159f );
    
    settings.set( "double name", 3.141593 );
    REQUIRE( settings.has( "double name" ) == true );
    const double default_double_value = 0.0;
    const double double_value = settings.get( "double name", default_double_value );
    REQUIRE( double_value == 3.141593 );
}

TEST_CASE( "Removing properties" )
{
    Settings settings;
    settings.set( "string name", "string value" );
    settings.erase( "string name" );
    REQUIRE( settings.has( "string name" ) == false );
    REQUIRE( settings.get( "string name" ) == "" );
    
    settings.set( "integer name", 12345 );
    settings.erase( "integer name" );
    REQUIRE( settings.has( "integer name" ) == false );
    const int default_integer_value = 0;
    const int integer_value = settings.get( "integer name", default_integer_value );
    REQUIRE( integer_value == default_integer_value );
    
    settings.set( "float name", 3.14159f );
    settings.erase( "float name" );
    REQUIRE( settings.has( "float name" ) == false );
    const float default_float_value = 0.0f;
    const float float_value = settings.get( "float name", default_float_value );
    REQUIRE( float_value == default_float_value );
    
    settings.set( "double name", 3.14159265359 );
    settings.erase( "double name" );
    REQUIRE( settings.has( "double name" ) == false );
    const double default_double_value = 0.0;
    const double double_value = settings.get( "double name", default_double_value );
    REQUIRE( double_value == default_double_value );
}

TEST_CASE( "Default property values" )
{
    Settings settings;
    
    const string default_string_value = "corvusoft;";
    const string string_value = settings.get( "string name", default_string_value );
    REQUIRE( string_value == default_string_value );
    
    const int default_integer_value = 7654;
    const int integer_value = settings.get( "integer name", default_integer_value );
    REQUIRE( integer_value == default_integer_value );
    
    const float default_float_value = 4.242f;
    const float float_value = settings.get( "float name", default_float_value );
    REQUIRE( float_value == default_float_value );
    
    const double default_double_value = 1.00000009;
    const double double_value = settings.get( "double name", default_double_value );
    REQUIRE( double_value == default_double_value );
}

TEST_CASE( "Property name case sensitivity" )
{
    Settings settings;
    settings.set( "string name", "string value" );
    REQUIRE( settings.has( "stRing name" ) == false );
    REQUIRE( settings.get( "stRing name" ) == "" );
    
    settings.set( "integer name", 12345 );
    REQUIRE( settings.has( "inteGer Name" ) == false );
    const int default_integer_value = 0;
    const int integer_value = settings.get( "inteGer Name", default_integer_value );
    REQUIRE( integer_value == default_integer_value );
    
    settings.set( "float name", 3.14159f );
    REQUIRE( settings.has( "float NAME" ) == false );
    const float default_float_value = 0.0f;
    const float float_value = settings.get( "float NAME", default_float_value );
    REQUIRE( float_value == default_float_value );
    
    settings.set( "double name", 3.141593 );
    REQUIRE( settings.has( "DOUBLE NAME" ) == false );
    const double default_double_value = 0.0;
    const double double_value = settings.get( "DOUBLE NAME", default_double_value );
    REQUIRE( double_value == default_double_value );
}

TEST_CASE( "Overwriting properies" )
{
    Settings settings;
    settings.set( "name", "value" );
    REQUIRE( settings.has( "name" ) == true );
    REQUIRE( settings.get( "name" ) == "value" );
    
    settings.set( "name", 12345 );
    REQUIRE( settings.has( "name" ) == true );
    const int default_integer_value = 0;
    const int integer_value = settings.get( "name", default_integer_value );
    REQUIRE( integer_value == 12345 );
    
    settings.set( "name", 3.14159f );
    REQUIRE( settings.has( "name" ) == true );
    const float default_float_value = 0.0f;
    const float float_value = settings.get( "name", default_float_value );
    REQUIRE( float_value == 3.14159f );
    
    settings.set( "name", 3.141593 );
    REQUIRE( settings.has( "name" ) == true );
    const double default_double_value = 0.0;
    const double double_value = settings.get( "name", default_double_value );
    REQUIRE( double_value == 3.141593 );
}

TEST_CASE( "Fetching incorrect data type from string" )
{
    Settings settings;
    settings.set( "name", "value" );
    REQUIRE( settings.has( "name" ) == true );
    REQUIRE( settings.get( "name" ) == "value" );
    
    const int default_integer_value = 0;
    const int integer_value = settings.get( "name", default_integer_value );
    REQUIRE( integer_value == default_integer_value );
    
    const float default_float_value = 0.0f;
    const float float_value = settings.get( "name", default_float_value );
    REQUIRE( float_value == default_float_value );
    
    const double default_double_value = 0.0;
    const double double_value = settings.get( "name", default_double_value );
    REQUIRE( double_value == default_double_value );
}

TEST_CASE( "Fetching incorrect data type from numeric" )
{
    Settings settings;
    settings.set( "name", 1.345678f );
    REQUIRE( settings.has( "name" ) == true );
    const float default_float_value = 0.0f;
    const float float_value = settings.get( "name", default_float_value );
    REQUIRE( float_value == 1.345678f );
    
    const string default_string_value = "";
    const string string_value = settings.get( "name" );
    REQUIRE( string_value == "1.345678" );
    
    const int default_integer_value = 0;
    const int integer_value = settings.get( "name", default_integer_value );
    REQUIRE( integer_value == 1 );
    
    const double default_double_value = 0.0;
    const double double_value = settings.get( "name", default_double_value );
    REQUIRE( double_value == 1.345678 );
}

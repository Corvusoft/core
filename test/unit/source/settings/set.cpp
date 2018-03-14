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
    REQUIRE_NOTHROW( settings.set( "", "" ) );
    REQUIRE_NOTHROW( settings.set( "", "empty value" ) );
    REQUIRE_NOTHROW( settings.set( "My name", "My value" ) );
    REQUIRE_NOTHROW( settings.set( "My name", "My new value" ) );
}

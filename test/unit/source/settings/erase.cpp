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
    REQUIRE_NOTHROW( settings.erase( "" ) );
    REQUIRE_NOTHROW( settings.erase( "unknown" ) );
}

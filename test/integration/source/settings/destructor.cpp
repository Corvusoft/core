//System Includes

//Project Includes
#include "corvusoft/core/settings.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces

//Project Namespaces
using corvusoft::core::Settings;

//External Namespaces

TEST_CASE( "Destructor." )
{
    auto settings = new Settings;
    settings->set( "string", "value" );
    settings->set( "integer", 1 );
    settings->set( "float", 3.14159f );
    settings->set( "double", 27.9769 );
    REQUIRE_NOTHROW( delete settings );
}

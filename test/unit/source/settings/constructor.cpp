//System Includes

//Project Includes
#include "corvusoft/core/settings.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces

//Project Namespaces
using corvusoft::core::Settings;

//External Namespaces

TEST_CASE( "Constructor." )
{
    REQUIRE_NOTHROW( new Settings );
}

//System Includes
#include <string>

//Project Includes
#include "corvusoft/core/byte.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;

//Project Namespaces
using corvusoft::core::Bytes;
using corvusoft::core::make_string;

//External Namespaces

TEST_CASE( "Make empty string." )
{
    auto data = make_string( Bytes( ) );
    REQUIRE( data.empty( ) );
}

TEST_CASE( "Convert bytes collection to string." )
{
    auto data = make_string( Bytes( { '1', '2', '3', '4', '5' } ) );
    REQUIRE( data == "12345" );
}

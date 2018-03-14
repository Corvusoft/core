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
using corvusoft::core::make_bytes;

//External Namespaces

TEST_CASE( "Make empty bytes collection." )
{
    auto data = make_bytes( );
    REQUIRE( data.empty( ) );
    
    data = make_bytes( "" );
    REQUIRE( data.empty( ) );
}

TEST_CASE( "Convert string to bytes collection." )
{
    auto data = make_bytes( "12345" );
    REQUIRE( data == Bytes( { '1', '2', '3', '4', '5' } ) );
}

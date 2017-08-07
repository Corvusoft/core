//System Includes
#include <string>

//Project Includes
#include "corvusoft/core/byte.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;

//Project Namespaces
using corvusoft::core::Byte;
using corvusoft::core::Bytes;
using corvusoft::core::make_bytes;
using corvusoft::core::make_string;

//External Namespaces

TEST_CASE( "make empty bytes" )
{
    Bytes data = make_bytes( );
    REQUIRE( data.empty( ) );
    REQUIRE( data.size( ) == 0 );
}

TEST_CASE( "convert string to bytes" )
{
    Bytes data = make_bytes( "12345" );
    REQUIRE( data == Bytes( { '1', '2', '3', '4', '5' } ) );
}

TEST_CASE( "convert bytes to string" )
{
    string data = make_string( Bytes( { '1', '2', '3', '4', '5' } ) );
    REQUIRE( data == "12345" );
}

TEST_CASE( "convert empty string to bytes" )
{
    Bytes data = make_bytes( "" );
    REQUIRE( data.empty( ) );
    REQUIRE( data.size( ) == 0 );
}

/*
 * Copyright 2013-2018, Corvusoft Ltd, All Rights Reserved.
 */

#pragma once

//System Includes
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace corvusoft
{
    namespace core
    {
        typedef uint8_t Byte;
        
        typedef std::vector< Byte > Bytes;
        
        static inline Bytes make_bytes( void )
        {
            return Bytes{ };
        }
        
        static inline Bytes make_bytes( const std::string& value )
        {
            return Bytes( value.begin( ), value.end( ) );
        }
        
        static inline std::string make_string( const Bytes& value )
        {
            return std::string( value.begin( ), value.end( ) );
        }
    }
}

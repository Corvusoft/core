/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

#ifndef _CORVUSOFT_CORE_BYTE_H
#define _CORVUSOFT_CORE_BYTE_H 1

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
    }
}

#endif  /* _CORVUSOFT_CORE_BYTE_H */

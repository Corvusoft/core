/*
 * Copyright 2013-2018, Corvusoft Ltd, All Rights Reserved.
 */

#pragma once

//System Includes
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace corvusoft
{
    //Forward Declarations
    
    namespace core
    {
        //Forward Declarations
        
        namespace detail
        {
            //Forward Declarations
            
            struct SettingsImpl
            {
                std::map< std::string, std::string > properties { };
                
                std::map< std::string, std::string >::iterator find( const std::string& name )
                {
                    return std::find_if( properties.begin( ), properties.end( ), [ &name ]( auto entry )
                    {
                        return std::equal( entry.first.begin( ), entry.first.end( ), name.begin( ), [ ]( auto lhs, auto rhs )
                        {
                            return std::tolower( lhs ) == std::tolower( rhs );
                        } );
                    } );
                }
            };
        }
    }
}

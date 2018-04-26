/*
 * Copyright 2013-2018, Corvusoft Ltd, All Rights Reserved.
 */

#pragma once

//System Includes
#include <memory>
#include <string>
#include <sstream>
#include <type_traits>

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
            struct SettingsImpl;
        }
        
        class Settings
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                Settings( void );
                
                virtual ~Settings( void );
                
                //Functionality
                void erase( const std::string& name );
                
                bool has( const std::string& name ) const;
                
                //Getters
                std::string get( const std::string& name, const std::string& default_value = "" ) const;
                
                template< typename Type, typename = std::enable_if_t< std::is_arithmetic< Type >::value > >
                Type get( const std::string& name, const Type default_value ) const
                {
                    std::istringstream stream( get( name ) );
                    
                    Type parameter;
                    stream >> parameter;
                    
                    return ( stream.fail( ) ) ? default_value : parameter;
                }
                
                //Setters
                void set( const std::string& name, const std::string& value );
                
                template< typename Type, typename = std::enable_if_t< std::is_arithmetic< Type >::value > >
                void set( const std::string& name, const Type value )
                {
                    set( name, std::to_string( value ) );
                }
                
                //Operators
                
                //Properties
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                Settings( const Settings& original ) = delete;
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                Settings& operator =( const Settings& value ) = delete;
                
                //Properties
                std::unique_ptr< detail::SettingsImpl > m_pimpl;
        };
    }
}

/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

#ifndef _CORVUSOFT_CORE_SETTINGS_H
#define _CORVUSOFT_CORE_SETTINGS_H 1

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
                
                bool has_property( const std::string& name ) const;
                
                //Getters
                float get_property( const std::string& name, const float default_value ) const;
                
                double get_property( const std::string& name, const double default_value ) const;
                
                std::string get_property( const std::string& name, const std::string& default_value = "" ) const;
                
                //use std::enable_if_t to remove the float and double signatures above.
                template< typename Type, typename std::enable_if< std::is_arithmetic< Type >::value, Type >::type = 0 >
                Type get_property( const std::string& name, const Type default_value ) const
                {
                    std::istringstream stream( get_property( name, "" ) );
                    
                    Type parameter;
                    stream >> parameter;
                    
                    return ( stream.fail( ) ) ? default_value : parameter;
                }
                
                //Setters
                void set_property( const std::string& name, const float value );
                
                void set_property( const std::string& name, const double value );
                
                void set_property( const std::string& name, const std::string& value );
                
                //use std::enable_if_t to remove the float and double signatures above.
                template< typename Type, typename std::enable_if< std::is_arithmetic< Type >::value, Type >::type = 0 >
                void set_property( const std::string& name, const Type value )
                {
                    set_property( name, std::to_string( value ) );
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

#endif  /* _CORVUSOFT_CORE_SETTINGS_H */

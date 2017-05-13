/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

//System Includes
#include <stdexcept>

//Project Includes
#include "corvusoft/core/settings.hpp"
#include "corvusoft/core/detail/settings_impl.hpp"

//External Includes

//System Namespaces
using std::stof;
using std::stod;
using std::string;
using std::to_string;
using std::unique_ptr;
using std::out_of_range;
using std::invalid_argument;

//Project Namespaces
using corvusoft::core::detail::SettingsImpl;

//External Namespaces

namespace corvusoft
{
    namespace core
    {
        Settings::Settings( void ) : m_pimpl( new SettingsImpl )
        {
            return;
        }
        
        Settings::~Settings( void )
        {
            return;
        }
        
        void Settings::erase( const string& name )
        {
            m_pimpl->properties.erase( name );
        }
        
        bool Settings::has_property( const string& name ) const
        {
            return m_pimpl->properties.count( name );
        }
        
        float Settings::get_property( const string& name, const float default_value ) const
        {
            float property = 0;
            
            try
            {
                property = stof( get_property( name ) );
            }
            catch ( const out_of_range )
            {
                property = default_value;
            }
            catch ( const invalid_argument )
            {
                property = default_value;
            }
            
            return property;
        }
        
        double Settings::get_property( const string& name, const double default_value ) const
        {
            double property = 0;
            
            try
            {
                property = stod( get_property( name ) );
            }
            catch ( const out_of_range )
            {
                property = default_value;
            }
            catch ( const invalid_argument )
            {
                property = default_value;
            }
            
            return property;
        }
        
        string Settings::get_property( const string& name, const string& default_value ) const
        {
            return ( has_property( name ) ) ? m_pimpl->properties.at( name ) : default_value;
        }
        
        void Settings::set_property( const string& name, const float value )
        {
            m_pimpl->properties[ name ] = ::to_string( value );
        }
        
        void Settings::set_property( const string& name, const double value )
        {
            m_pimpl->properties[ name ] = ::to_string( value );
        }
        
        void Settings::set_property( const string& name, const string& value )
        {
            m_pimpl->properties[ name ] = value;
        }
    }
}

/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

//System Includes

//Project Includes
#include "corvusoft/core/settings.hpp"
#include "corvusoft/core/detail/settings_impl.hpp"

//External Includes

//System Namespaces
using std::string;
using std::unique_ptr;

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
        
        bool Settings::has( const string& name ) const
        {
            return m_pimpl->properties.count( name );
        }
        
        string Settings::get( const string& name, const string& default_value ) const
        {
            return ( has( name ) ) ? m_pimpl->properties.at( name ) : default_value;
        }
        
        void Settings::set( const string& name, const string& value )
        {
            m_pimpl->properties[ name ] = value;
        }
    }
}

/*
 * Copyright 2013-2018, Corvusoft Ltd, All Rights Reserved.
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
            auto iterator = m_pimpl->find( name );
            if ( iterator not_eq m_pimpl->properties.end( ) )
                m_pimpl->properties.erase( iterator );
        }
        
        bool Settings::has( const string& name ) const
        {
            return m_pimpl->find( name ) not_eq m_pimpl->properties.end( );
        }
        
        string Settings::get( const string& name, const string& default_value ) const
        {
            auto iterator = m_pimpl->find( name );
            if ( iterator == m_pimpl->properties.end( ) )
                return default_value;
                
            return iterator->second;
        }
        
        void Settings::set( const string& name, const string& value )
        {
            auto iterator = m_pimpl->find( name );
            if ( iterator not_eq m_pimpl->properties.end( ) )
                iterator->second = value;
            else
                m_pimpl->properties.emplace( name, value );
        }
    }
}

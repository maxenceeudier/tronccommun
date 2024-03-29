/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access_elements.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:17:01 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"


namespace ft 
{
    template<class Key, class T, class Compare , class Allocator >
    T& map<Key, T, Compare, Allocator>::at( const Key& key )
    {
        typename map<Key, T, Compare, Allocator>::iterator it = this->find(key);
        if (it == this->end())
        {
            std::string what = "vector::_out_of_range_";
            throw std::out_of_range(what);
        }
        return (it->second);
    }
    

    template<class Key, class T, class Compare , class Allocator >
    const T& map<Key, T, Compare, Allocator>::at( const Key& key ) const
    {
        typename map<Key, T, Compare, Allocator>::const_iterator it = this->find(key);
        if (it == this->end())
        {
            std::string what = "vector::_out_of_range_";
            throw std::out_of_range(what);
        }
        return (it->second);
    }


    template<class Key, class T, class Compare , class Allocator >
    T& map<Key, T, Compare, Allocator>::operator[]( const Key& key )
    {
        typename map<Key, T, Compare, Allocator>::iterator it = this->find(key);
        if (it == this->end())
        {
            this->insert(value_type(key, T()));
            return (this->find(key)->second);
        }
        return (it->second);
    }
}
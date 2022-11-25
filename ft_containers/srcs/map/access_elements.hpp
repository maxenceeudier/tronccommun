/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_elements.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/23 09:45:32 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
//#include "../../Include/include.h"

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
            //if (_gost->parent)
            //    _gost->parent->right = NULL;  

            this->insert(value_type(key, T()));

            //============================
            //_gost->parent = _tree.maxValueNode(_tree.getRoot());
            //_gost->parent->right = _gost;

            return (this->find(key)->second);
        }
        return (it->second);
    }
}
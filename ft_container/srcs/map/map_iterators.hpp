/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:34 by meudier           #+#    #+#             */
/*   Updated: 2022/12/05 12:18:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "mapIterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::begin()
    {
        return (iterator(_tree.minValueNode(_tree.getRoot())));
    }
    
   template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::begin() const
    {
        return (const_iterator((_tree.minValueNode(_tree.getRoot()))));
    }
    

    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::end()
    {
        iterator    gost_it = iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::end() const
    {
        const_iterator    gost_it = const_iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin()
    {
        reverse_iterator    gost_it = reverse_iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator >  
    typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin() const
    {
        const_reverse_iterator    gost_it = const_reverse_iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator >  
    typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rend()
    {
        reverse_iterator    gost_it = reverse_iterator(this->begin());
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator >  
    typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rend() const
    {
        const_reverse_iterator    gost_it = const_reverse_iterator(this->begin());
        return (gost_it);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:34 by meudier           #+#    #+#             */
/*   Updated: 2022/12/01 17:35:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
#include "setIterator.hpp"

namespace ft
{
    template<class Key, class Compare , class Allocator > 
    typename ft::set<Key, Compare, Allocator>::iterator ft::set<Key, Compare, Allocator>::begin()
    {
        return (iterator(_tree.minValueNode(_tree.getRoot())));
    }
    
   template<class Key, class Compare , class Allocator > 
    typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::begin() const
    {
        return (const_iterator((_tree.minValueNode(_tree.getRoot()))));
    }
    

    template<class Key, class Compare , class Allocator > 
    typename ft::set<Key, Compare, Allocator>::iterator ft::set<Key, Compare, Allocator>::end()
    {
        iterator    gost_it = iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class Compare , class Allocator > 
    typename ft::set<Key, Compare, Allocator>::const_iterator ft::set<Key, Compare, Allocator>::end() const
    {
        const_iterator    gost_it = const_iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class Compare , class Allocator > 
    typename ft::set<Key, Compare, Allocator>::reverse_iterator ft::set<Key, Compare, Allocator>::rbegin()
    {
        reverse_iterator    gost_it = reverse_iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class Compare , class Allocator >  
    typename ft::set<Key, Compare, Allocator>::const_reverse_iterator ft::set<Key, Compare, Allocator>::rbegin() const
    {
        const_reverse_iterator    gost_it = const_reverse_iterator(_gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class Compare , class Allocator >  
    typename ft::set<Key, Compare, Allocator>::reverse_iterator ft::set<Key, Compare, Allocator>::rend()
    {
        reverse_iterator    gost_it = reverse_iterator(this->begin());
        return (gost_it);
    }
    
    template<class Key, class Compare , class Allocator >  
    typename ft::set<Key, Compare, Allocator>::const_reverse_iterator ft::set<Key, Compare, Allocator>::rend() const
    {
        const_reverse_iterator    gost_it = const_reverse_iterator(this->begin());
        return (gost_it);
    }
}
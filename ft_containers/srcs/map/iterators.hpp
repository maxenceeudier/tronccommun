/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:34 by meudier           #+#    #+#             */
/*   Updated: 2022/10/14 18:24:16 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "mapIterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::begin()
    {return (iterator(_tree.minValueNode(_tree.getRoot())));}
    
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::begin() const
    {return (const_iterator(_tree.minValueNode(_tree.getRoot())));}
    

    // a re travailler
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::end()
    {return (iterator(_tree.maxValueNode(_tree.getRoot())));}
    
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::end() const
    {return (const_iterator(_tree.maxValueNode(_tree.getRoot())));}
    
    /*template<class Key, class T, class Compare , class Allocator > 
    ft::map<Key, T, Compare, Allocator>::reverse_iterator rbegin();
    
    template<class Key, class T, class Compare , class Allocator >  
    ft::map<Key, T, Compare, Allocator>::const_reverse_iterator rbegin() const;
    
    template<class Key, class T, class Compare , class Allocator >  
    ft::map<Key, T, Compare, Allocator>::reverse_iterator rend();
    
    template<class Key, class T, class Compare , class Allocator >  
    ft::map<Key, T, Compare, Allocator>::const_reverse_iterator rend() const;*/
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:34 by meudier           #+#    #+#             */
/*   Updated: 2022/11/22 13:58:49 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
//#include "../../Include/include.h"
#include "mapIterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::begin()
    {return (iterator(_tree.minValueNode(_tree.getRoot())));}
    
   template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::begin() const
    {return (const_iterator((_tree.minValueNode(_tree.getRoot()))));}
    

    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::end()
    {
        typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        Node<value_type>    *gost = _allocNode.allocate(1);
        _allocNode.construct(gost, Node<value_type>());
        gost->parent = _tree.maxValueNode(_tree.getRoot());
        iterator    gost_it = iterator(gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::end() const
    {
        typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        Node<value_type>    *gost = _allocNode.allocate(1);
        _allocNode.construct(gost, Node<value_type>());
        gost->parent = (_tree.maxValueNode(_tree.getRoot()));
        const_iterator    gost_it = const_iterator(gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator > 
    typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin()
    {
        return (reverse_iterator(_tree.maxValueNode(_tree.getRoot())));
    }
    
    template<class Key, class T, class Compare , class Allocator >  
    typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rbegin() const
    {
        return (const_reverse_iterator((_tree.maxValueNode(_tree.getRoot()))));
    }
    
    template<class Key, class T, class Compare , class Allocator >  
    typename ft::map<Key, T, Compare, Allocator>::reverse_iterator ft::map<Key, T, Compare, Allocator>::rend()
    {
        typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        Node<value_type>    *gost = _allocNode.allocate(1);
        _allocNode.construct(gost, Node<value_type>());
        gost->parent = _tree.maxValueNode(_tree.getRoot());
        reverse_iterator    gost_it = reverse_iterator(gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
    
    template<class Key, class T, class Compare , class Allocator >  
    typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator ft::map<Key, T, Compare, Allocator>::rend() const
    {
        typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        Node<value_type>    *gost = _allocNode.allocate(1);
        _allocNode.construct(gost, Node<value_type>());
        gost->parent = (_tree.maxValueNode(_tree.getRoot()));
        const_reverse_iterator    gost_it = const_reverse_iterator(gost);
        gost_it.set_is_gost(1);
        return (gost_it);
    }
}
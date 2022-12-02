/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic_functions.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:39 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/01 17:19:24 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
//#include "../../Include/include.h"

namespace ft
{

    template<class Key, class Compare , class Allocator >
    set<Key, Compare, Allocator>::set():  _comp(Compare()),  _alloc(Allocator()), _tree(RBTree())
    {
        _gost = _allocNode.allocate(1);
        _allocNode.construct(_gost, Node<value_type>());
    }

    template<class Key, class Compare , class Allocator >
    set<Key, Compare, Allocator>::set(const Compare& comp, const Allocator& alloc) \
    :  _comp(comp), _alloc(alloc), _tree(RBTree())
    {
        _gost = _allocNode.allocate(1);
        _allocNode.construct(_gost, Node<value_type>());
    }
    
    template<class Key, class Compare , class Allocator >
    set<Key, Compare, Allocator>::set( const set& other ) :  ft::RBTree<ft::pair<Key, T>, typename Allocator::template rebind<ft::Node<ft::pair<Key, T> > >::other, Compare >()
    {
        _gost = _allocNode.allocate(1);
        _allocNode.construct(_gost, Node<value_type>());
    
        *this = other;
    }
    
    template<class Key, class Compare , class Allocator >
    set<Key, Compare, Allocator>::~set()
    {
        if (_gost->parent)
            _gost->parent->right = NULL;
        
        _allocNode.destroy(_gost);
        _allocNode.deallocate(_gost, 1);
        
    }

    template<class Key, class Compare , class Allocator >
    set<Key, Compare, Allocator> &set<Key, Compare, Allocator>::operator=( const set& other )
    {
        _alloc = other._alloc;
        _comp = other._comp;

        if (_gost->parent)
            _gost->parent->right = NULL;
        if (other._gost->parent)
            other._gost->parent->right = NULL;
    
        
        this->_tree = other._tree;

        //==========================
        other._gost->parent = other._tree.maxValueNode(other._tree.getRoot());
        if (other._gost->parent)
            other._gost->parent->right = other._gost;
            
        _gost->parent = _tree.maxValueNode(_tree.getRoot());
        if (_gost->parent)
            _gost->parent->right = _gost;
        return (*this);
    }

    template<class Key, class Compare , class Allocator >
    typename set<Key, Compare, Allocator>::allocator_type set<Key, Compare, Allocator>::get_allocator() const {return (_alloc);}
}

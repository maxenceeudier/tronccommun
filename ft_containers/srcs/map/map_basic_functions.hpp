/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_basic_functions.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:39 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/02 10:06:41 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
//#include "../../Include/include.h"

namespace ft
{

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map(): _T_default(T()), _comp(Compare()),  _alloc(Allocator()), _tree(RBTree())
    {
        //typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        _gost = _allocNode.allocate(1);
        _allocNode.construct(_gost, Node<value_type>());
        //_gost->parent = _tree.maxValueNode(_tree.getRoot());
        //_gost->parent->right = _gost;
        
    }

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map(const Compare& comp, const Allocator& alloc) \
    :  _comp(comp), _alloc(alloc), _tree(RBTree())
    {
        //typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        _gost = _allocNode.allocate(1);
        _allocNode.construct(_gost, Node<value_type>());
        //_gost->parent = _tree.maxValueNode(_tree.getRoot());
        //_gost->parent->right = _gost;
    }
    
    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map( const map& other ) :  ft::RBTree<ft::pair<Key, T>, typename Allocator::template rebind<ft::Node<ft::pair<Key, T> > >::other >()
    {
        
        _gost = _allocNode.allocate(1);
        _allocNode.construct(_gost, Node<value_type>());
    
        *this = other;
    }
    
    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::~map()
    {
        if (_gost->parent)
            _gost->parent->right = NULL;
        
        //typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        _allocNode.destroy(_gost);
        _allocNode.deallocate(_gost, 1);
        
    }

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator> &map<Key, T, Compare, Allocator>::operator=( const map& other )
    {
        _alloc = other._alloc;
        _comp = other._comp;

        if (_gost->parent)
            _gost->parent->right = NULL;
        if (other._gost->parent)
            other._gost->parent->right = NULL;
    
        //this->clear();
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

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const {return (_alloc);}
}

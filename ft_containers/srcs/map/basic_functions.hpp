/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:39 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/13 11:39:00 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map(): _alloc(Allocator()), _comp(Compare()){}

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map(const Compare& comp, const Allocator& alloc) \
    : _alloc(alloc), _comp(comp){}

    
    //template< class InputIt >
    //map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
    
    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map( const map& other ): _alloc(other._alloc), _comp(other._comp)
    {*this = other;}
    
    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::~map(){_tree.getRoot() = _tree.clearRBTree(_tree.getRoot());}

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator> &map<Key, T, Compare, Allocator>::operator=( const map& other )
    {
        _alloc = other._alloc;
        _comp = other._comp;
        _tree.getRoot() = _tree.copyTree(other._tree.getRoot());
        return (*this);
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const {return (_alloc);}
}

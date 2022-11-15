/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:39 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/15 17:32:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map(): _T_default(T()), _comp(Compare()),  _alloc(Allocator()){}

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map(const Compare& comp, const Allocator& alloc) \
    :  _T_default(T()), _comp(comp), _alloc(alloc) {}
    
    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::map( const map& other )
    {*this = other;}
    
    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator>::~map(){}

    template<class Key, class T, class Compare , class Allocator >
    map<Key, T, Compare, Allocator> &map<Key, T, Compare, Allocator>::operator=( const map& other )
    {
        _T_default = other._T_default;
        _alloc = other._alloc;
        _comp = other._comp;
        this->clear();
        _tree.setRoot(_tree.copyTree(other._tree.getRoot()));
        return (*this);
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const {return (_alloc);}
}

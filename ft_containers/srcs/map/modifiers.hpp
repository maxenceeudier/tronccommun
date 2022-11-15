/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:46 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/15 17:11:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator >
    void     map<Key, T, Compare, Allocator>::clear(void)
    {
        this->_tree.setRoot(this->_tree.clearRBTree(this->_tree.getRoot()));
    }

    template<class Key, class T, class Compare , class Allocator >
    pair< typename map<Key, T, Compare, Allocator>::iterator , bool > map<Key, T, Compare, Allocator>::insert( const value_type& value )
    {
        bool b = false;
        if ((this->find(value.first)) == this->end())
        {
            _tree.insertValue(value);
            b = true;
        }
        return (pair<iterator, bool>((this->find(value.first)), b));
    }


    template<class Key, class T, class Compare , class Allocator >
    void map<Key, T, Compare, Allocator>::swap( map& other )
    {
        ft::swap(*this, other);
    }
}
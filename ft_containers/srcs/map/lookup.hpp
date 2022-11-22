/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:08 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/22 12:29:31 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::find( const Key& key )
    {

        /*typename map<Key, T, Compare, Allocator>::iterator it = this->begin();
        
        while (it != this->end())
        {
            if (it->first == key )
                break ;
            it++;
        }
        return (it);*/

        Node<value_type>    *node = this->_tree.getRoot();
        while (node)
        {
            if (_comp(node->data.first, key))
                node = node->right;
            else if (_comp(key, node->data.first))
                node = node->left;
            if (node && node->data.first == key)
                break;
        }
        if (node)
            return (iterator(node));
        return (this->end());
    }

    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::find( const Key& key ) const
    {
        Node< value_type>    *node = (this->_tree.getRoot());
        while (node)
        {
            if (_comp(node->data.first, key))
                node = node->right;
            else if (_comp(key, node->data.first))
                node = node->left;
            if (node && node->data.first == key)
                break;
        }
        if (node)
            return (const_iterator(node));
        return (this->end());
    }

    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::size_type  map<Key, T, Compare, Allocator>::count(const Key& key ) const
    {
        return (this->find(key) != this->end());    
    }

    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::lower_bound( const Key& key )
    {
        return (this->find(key));
    }
    
    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::lower_bound( const Key& key ) const
    {
        return (this->find(key));
    }

    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::upper_bound( const Key& key )
    {
        return (++(this->find(key)));
    }
            
    template<class Key, class T, class Compare , class Allocator > 
    typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::upper_bound( const Key& key ) const
    {
         return (++(this->find(key)));
    }


    template<class Key, class T, class Compare , class Allocator > 
    pair< typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator > map<Key, T, Compare, Allocator>::equal_range( const Key& key )
    {
        return (pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key)));
    }

    template<class Key, class T, class Compare , class Allocator > 
    pair< typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator > map<Key, T, Compare, Allocator>::equal_range( const Key& key ) const
    {
        return (pair<const_iterator, const_iterator>(this->lower_bound(key), this->upper_bound(key)));
    }
    
}
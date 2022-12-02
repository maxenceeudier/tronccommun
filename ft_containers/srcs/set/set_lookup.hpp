/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lookup.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:08 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/02 09:01:00 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::iterator set<Key, Compare, Allocator>::find( const Key& key )
    {
        Node<value_type>    *node = this->_tree.getRoot();
        while (node)
        {
            if (_comp(node->data, key))
                node = node->right;
            else if (_comp(key, node->data))
                node = node->left;
            if (node && node->data == key)
                break;
        }
        if (node)
            return (iterator(node));
        return (this->end());
    }

    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::const_iterator set<Key, Compare, Allocator>::find( const Key& key ) const
    {
        Node< value_type>    *node = (this->_tree.getRoot());
        if (_gost->parent)
            _gost->parent->right = NULL;
            
        while (node)
        {
            if (_comp(node->data, key))
                node = node->right;
            else if (_comp(key, node->data))
                node = node->left;
            if (node && node->data == key)
                break;
        }
        
        _gost->parent->right = _gost;
         
        if (node)
            return (const_iterator(node));
        return (this->end());
    }

    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::size_type  set<Key, Compare, Allocator>::count(const Key& key ) const
    {
        return (this->find(key) != this->end());    
    }

    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::iterator set<Key, Compare, Allocator>::lower_bound( const Key& key )
    {
        iterator gotIt = this->find(key);
        if (gotIt == this->end())
        {
            for (iterator it = this->begin(); it != this->end(); it++)
            {
                if (*it > key)
                    return (it);
            }
        }
        return (gotIt);
    }
    
    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::const_iterator set<Key, Compare, Allocator>::lower_bound( const Key& key ) const
    {
        const_iterator gotIt = this->find(key);
        if (gotIt == this->end())
        {
            for (const_iterator it = this->begin(); it != this->end(); it++)
            {
                if (*it > key)
                    return (it);
            }
        }
        return (gotIt);
    }

    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::iterator set<Key, Compare, Allocator>::upper_bound( const Key& key )
    {
        iterator gotIt = this->find(key);
        
        for (iterator it = this->begin(); it != this->end(); it++)
        {
            if (*it > key)
                return (it);
        }
        
        return (this->end());
    }
            
    template<class Key, class Compare , class Allocator > 
    typename set<Key, Compare, Allocator>::const_iterator set<Key, Compare, Allocator>::upper_bound( const Key& key ) const
    {
        const_iterator gotIt = this->find(key);
        
        for (const_iterator it = this->begin(); it != this->end(); it++)
        {
            if (*it > key)
                return (it);
        }
        
        return (this->end());
    }


    template<class Key, class Compare , class Allocator > 
    pair< typename set<Key, Compare, Allocator>::iterator, typename set<Key, Compare, Allocator>::iterator > set<Key, Compare, Allocator>::equal_range( const Key& key )
    {
        return (pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key)));
    }

    template<class Key, class Compare , class Allocator > 
    pair< typename set<Key, Compare, Allocator>::const_iterator, typename set<Key, Compare, Allocator>::const_iterator > set<Key, Compare, Allocator>::equal_range( const Key& key ) const
    {
        return (pair<const_iterator, const_iterator>(this->lower_bound(key), this->upper_bound(key)));
    }
    
}
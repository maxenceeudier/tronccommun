/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:46 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/16 15:15:20 by meudier          ###   ########.fr       */
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
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::insert( iterator hint, const value_type& value )
    {
        iterator    it = this->find(value.first);
        if (it != this->end())
            return (it);

        hint--;
        Node<value_type>    *node = new Node<value_type>;
        node->data = value;
        node->color = RED;
        node->left = NULL;
        node->right = NULL;
        node->parent = hint.getNode()->parent;
        hint.getNode()->parent = node;
        
        if (node->parent && node->parent->right == hint.getNode())
            node->parent->right = node;
        else if (node->parent)
            node->parent->left = node;
        else
            this->_tree.setRoot(node);
        
        if (_comp(hint->first, node->data.first))
            node->left = hint.getNode();
        else if (_comp(node->data.first, hint->first))
            node->right = hint.getNode();

        this->_tree.fixInsertRBTree(node);
        return (this->find(node->data.first));
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::erase( iterator pos )
    {
        this->_tree.deleteValue(*pos);
        return (this->end());
    }
    
    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::erase( iterator first, iterator last )
    {
        
    }
   
    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::erase( const Key& key )
    {
        iterator    it = this->find(key);
        if (it == this->end())
            return (0);
        
        this->_tree.deleteValue(*it);
        return (1);
    }

    template<class Key, class T, class Compare , class Allocator >
    void map<Key, T, Compare, Allocator>::swap( map& other )
    {
        ft::swap(*this, other);
    }
}
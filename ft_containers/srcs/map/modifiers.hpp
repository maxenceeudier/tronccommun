/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:46 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/17 11:55:45 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "../vector/vector.h"
//#include "../../Include/include.h"

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
        typename Allocator::template rebind<ft::Node<value_type> >::other  _allocNode;
        Node<value_type>    *node = _allocNode.allocate(1);
        _allocNode.construct(node, Node<value_type>());
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
    void map<Key, T, Compare, Allocator>::erase( iterator pos )
    {this->_tree.deleteValue(*pos);}
    
    template<class Key, class T, class Compare , class Allocator >
    void map<Key, T, Compare, Allocator>::erase( iterator first, iterator last )
    {
        ft::vector<ft::pair<Key, T> >  vec;
        size_t                          i = 0;
        while (first != last)
            vec.push_back(*(first++));
        while (i < vec.size())
            this->_tree.deleteValue(vec[i++]);
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
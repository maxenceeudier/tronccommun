/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifiers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:46 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 15:30:10 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <vector>

namespace ft
{
    template<class Key, class T, class Compare , class Allocator >
    void     map<Key, T, Compare, Allocator>::clear(void)
    {
        if (_gost->parent)
            _gost->parent->right = NULL;
        
        this->_tree.setRoot(this->_tree.clearRBTree(this->_tree.getRoot()));
        
        _gost->parent = NULL;
    }

    template<class Key, class T, class Compare , class Allocator >
    pair< typename map<Key, T, Compare, Allocator>::iterator , bool > map<Key, T, Compare, Allocator>::insert( const value_type& value )
    {
        bool b = false;
        if ((this->find(value.first)) == this->end())
        {
            if (_gost->parent)
                _gost->parent->right = NULL;
            
            _tree.insertValue(value);
            b = true;
            
            _gost->parent =  _tree.maxValueNode(_tree.getRoot());
            if (_gost->parent)
                _gost->parent->right = _gost;
        }
        return (pair<iterator, bool>((this->find(value.first)), b));
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::insert( iterator hint, const value_type& value )
    {
        if (this->find(value.first) == this->end())
        {
            if (_gost->parent)
                _gost->parent->right = NULL;
            
            (void)hint;
            this->_tree.insertValue(value);

            _gost->parent = _tree.maxValueNode(_tree.getRoot());
            if (_gost->parent)
                _gost->parent->right = _gost;
        }
        return (this->find(value.first));
    }

    template<class Key, class T, class Compare , class Allocator >
    void map<Key, T, Compare, Allocator>::erase( iterator pos )
    {
        if (_gost->parent)
            _gost->parent->right = NULL;
        
        this->_tree.deleteValue(*pos);

        _gost->parent = _tree.maxValueNode(_tree.getRoot());
        if (_gost->parent)
            _gost->parent->right = _gost;
    }
    
    template<class Key, class T, class Compare , class Allocator >
    void map<Key, T, Compare, Allocator>::erase( iterator first, iterator last )
    {
        ft::vector<value_type>  vec;
        size_t                  i = 0;

        while (first != last)
        {
            vec.push_back((*(first++)));
        }

        if (_gost->parent)
            _gost->parent->right = NULL;
        
        
        while (i < vec.size())
        {
            this->_tree.deleteValue(vec[i++]);
        }

        _gost->parent = _tree.maxValueNode(_tree.getRoot());
        if (_gost->parent)
            _gost->parent->right = _gost;
        
    }
   
    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::erase( const Key& key )
    {
        iterator    it = this->find(key);
        if (it == this->end())
            return (0);

        if (_gost->parent)
            _gost->parent->right = NULL;   
        
        this->_tree.deleteValue(*it);

        _gost->parent = _tree.maxValueNode(_tree.getRoot());
        if (_gost->parent)
            _gost->parent->right = _gost;
        
        return (1);
    }

    template<class Key, class T, class Compare , class Allocator >
    void map<Key, T, Compare, Allocator>::swap( map& other )
    {
        if (_gost->parent)
            _gost->parent->right = NULL;
        if (other._gost->parent)
            other._gost->parent->right = NULL;
    
        node_type *temp = _tree.getRoot();
        *_tree.getPtrToRoot() = other._tree.getRoot();
        *other._tree.getPtrToRoot() = temp;

        other._gost->parent = other._tree.maxValueNode(other._tree.getRoot());
        if (other._gost->parent)
            other._gost->parent->right = other._gost;
            
        _gost->parent = _tree.maxValueNode(_tree.getRoot());
        if (_gost->parent)
            _gost->parent->right = _gost;
        
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:22:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/14 18:26:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
#include "../../utils/iterator_traits.hpp"
#include "../../utils/utils.h"

namespace ft
{

    template <class Tkey, class Tvalue>
    class	mapIterator
    {
    public:

        typedef typename ft::pair<Tkey, Tvalue>     pair;
        typedef typename ft::Node<pair>             value_type;
        typedef value_type&				            reference;
        typedef const value_type&		            const_reference;
        typedef value_type*				            pointer;
        typedef const value_type*		            const_pointer;
        typedef typename std::ptrdiff_t             difference_type;
        typedef ft::random_access_iterator_tag      iterator_category;

        mapIterator(void) : _is_gost(false) {};
        mapIterator(pointer ptr) : _is_gost(false) {node = ptr;};
        mapIterator(mapIterator const &src): _is_gost(src._is_gost)
        {
            if (_is_gost)
                node = new value_type(*(src.node));
            else
                node = src.node;
        } ;

        virtual ~mapIterator()
        {
            if (_is_gost)
                delete node;
        };

        mapIterator &operator=(mapIterator const &src) 
        {
            if (_is_gost)
                delete node;
            node = src.node;
            return (*this);
        };

        // INCREMENTERS
        mapIterator operator ++() 
        {
            if (node)
            {
                if (_is_the_last(node))
                {
                    pointer _gost = new value_type();
                    _gost->parent = node;
                    _is_gost = true;
                    node = _gost;
                    return (*this);
                }

                if (node->right)
                    node = _smallest(node->right);
                else
                {
                    if (node->parent && node == node->parent->right)
                    {
                        while (node->parent && node == node->parent->right)
                            node = node->parent;
                    }
                    node = node->parent;
                }
            } 
            return (*this);
        };// ++a
        
        
        mapIterator operator ++(int)
        {
            mapIterator temp = *this;
            ++(*this);
            return (temp);
        };// a++

        
        mapIterator operator --()
        {
            mapIterator temp = *this;
            --(*this);
            return (temp);
        };// --a

        
        mapIterator operator --(int)
        {
            pointer temp = node;
            if (node)
            {
                if (node->left)
                    node = _biggest(node->left);
                else
                {
                    if (node->parent && node == node->parent->left)
                    {
                        while (node->parent && node == node->parent->left)
                            node = node->parent;
                    }
                    node = node->parent;
                }
            }
            return (mapIterator(temp));
        };	// a--


        //DEREFERENCING & ADDRESS STUFF
        pair* operator->(){return (&(node->data));};
        pair* operator->() const {return (&(node->data));};

        static const bool input_iter = true;

        private:
            pointer _smallest(pointer node)
            {
                while (node && node->left)
                    node = node->left;
                return (node);
            };
            
            pointer _biggest(pointer node)
            {
                while (node && node->right)
                    node = node->right;
                return (node);    
            };

            bool    _is_the_last(pointer node)
            {
                pointer temp = node;

                while (node && node->parent)
                    node = node->parent;
                return (temp == _biggest(node));
            };

            bool    _is_the_first(pointer node)
            {
                pointer temp = node;

                while (node && node->parent)
                    node = node->parent;
                return (temp == _smallest(node));
            };
            
            bool        _is_gost;
            pointer     node;
    };

    template< class T1, class T2>
    bool operator==( const ft::mapIterator<T1, T2>& lhs, \
    const ft::mapIterator<T1, T2>& rhs ){return (lhs.operator->() == rhs.operator->());};

    template< class T1, class T2>
    bool operator!=( const ft::mapIterator<T1, T2>& lhs, \
    const ft::mapIterator<T1, T2>& rhs ){return (lhs.operator->() != rhs.operator->());};

}
#endif
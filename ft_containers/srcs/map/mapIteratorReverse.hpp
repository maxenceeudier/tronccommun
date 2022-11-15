/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIteratorReverseReverse.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:43 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/15 12:11:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOREVERSE_HPP
#define ITERATOREVERSE_HPP
#include "../../utils/iterator_traits.hpp"
#include "../../utils/utils.h"

namespace ft
{
    template < class pair>
    class	mapIteratorReverse
    {
    public:

        typedef pair                                value_type;
        typedef Node<pair>                          node_type;
        typedef value_type&				            reference;
        typedef node_type&				            node_reference;
        typedef const value_type&		            const_reference;
        typedef const node_type&				    node_const_reference;
        typedef value_type*				            pointer;
        typedef node_type*				            node_pointer;
        typedef const value_type*		            const_pointer;
        typedef const node_type*				    node_const_pointer;
        typedef typename std::ptrdiff_t             difference_type;
        typedef ft::random_access_iterator_tag      iterator_category;

        mapIteratorReverse(void) : _is_gost(false) {};
        mapIteratorReverse(node_pointer ptr) : _is_gost(false) {node = ptr;};
        mapIteratorReverse(node_const_pointer ptr) : _is_gost(false) {node = ptr;};
        mapIteratorReverse(mapIteratorReverse const &src): _is_gost(src._is_gost)
        {
            if (this->_is_gost)
                node = new node_type(*(src.node));
            else
                node = src.node;
        };

        virtual ~mapIteratorReverse()
        {
            if (_is_gost)
                delete node;
        };

        mapIteratorReverse &operator=(mapIteratorReverse const &src) 
        {
            if (_is_gost)
                delete node;
            _is_gost = src._is_gost;
            if (this->_is_gost)
                node = new node_type(*(src.node));
            else
                node = src.node;
            return (*this);
        };

        // INCREMENTERS
        mapIteratorReverse operator --() 
        {
            if (node)
            {
                if (_is_gost)
                {
                    node_pointer temp = node->parent;
                    delete node;
                    node = temp;
                    _is_gost = false;
                    return (*this);
                }
                if (_is_the_last(node) == node)
                {
                    node_pointer gost = new node_type();
                    gost->parent = node;
                    _is_gost = true;
                    node = gost;
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
        
        
        mapIteratorReverse operator --(int)
        {
            mapIteratorReverse temp = *this;
            --(*this);
            return (temp);
        };// a++


        mapIteratorReverse operator-(int n)
        {
            while (n--)
                ++(*this);
            return (*this);
        };

        
        mapIteratorReverse operator ++()
        {
            if (node)
            {
                if (_is_gost)
                {
                    node_pointer temp = node->parent;
                    delete node;
                    node = temp;
                    _is_gost = false;
                    return (*this);
                }
                if (_is_the_first(node) == node)
                {
                    node_pointer gost = new node_type();
                    gost->parent = _is_the_last(node);
                    _is_gost = true;
                    this->node = gost;
                    return (*this);
                }
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
            return (*this);
        };// --a

        
        mapIteratorReverse operator ++(int)
        {
            mapIteratorReverse temp = *this;
            ++(*this);
            return (temp);
        };	// a--


        mapIteratorReverse operator+(int n)
        {
            while (n--)
                ++(*this);
            return (*this);
        };

        //DEREFERENCING & ADDRESS STUFF
        pointer           operator->(){return (&(node->data));};
        const_pointer     operator->() const {return (&(node->data));};
        reference         operator*(){return ((node->data));};
        const_reference   operator*() const {return ((node->data));};
        
        node_pointer getNode(){return (node);}

        static const bool input_iter = true;

        void    set_is_gost(bool a){_is_gost = a;};

        private:
            node_pointer _smallest(node_pointer node)
            {
                while (node && node->left)
                    node = node->left;
                return (node);
            };
            
            node_pointer _biggest(node_pointer node)
            {
                while (node && node->right)
                    node = node->right;
                return (node);    
            };

            node_pointer    _is_the_last(node_pointer node)
            {
                while (node && node->parent)
                    node = node->parent;
                return (_biggest(node));
            };

            node_pointer    _is_the_first(node_pointer node)
            {
                while (node && node->parent)
                    node = node->parent;
                return (_smallest(node));
            };
            
            bool            _is_gost;
            node_pointer    node;
    };

    template< class T1>
    bool operator==( const ft::mapIteratorReverse< T1> & lhs, \
    const ft::mapIteratorReverse<T1> & rhs )
    {return (*(lhs.operator->()) == *(rhs.operator->()));};

    template<class T1>
    bool operator!=( const ft::mapIteratorReverse< T1> & lhs, \
    const ft::mapIteratorReverse<T1>& rhs ){return (!(lhs == rhs));};
}

#endif

   
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIteratorReverseReverseReverse.hpp                             :+:      :+:    :+:   */
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
#include "mapIterator.hpp"
//#include "../../Include/include.h"



namespace ft
{  
    template < class pair, bool B = false >
    class	mapIteratorReverse
    {
    public:
        
        typedef pair                                value_type;
        typedef Node<pair>                          node_type;
        typedef node_type&				            node_reference;
        typedef const value_type&		            const_reference;
        typedef const node_type&				    node_const_reference;
        typedef node_type*				            node_pointer;
        typedef const value_type*		            const_pointer;
        typedef const node_type*				    node_const_pointer;
        typedef typename std::ptrdiff_t             difference_type;
        typedef ft::random_access_iterator_tag      iterator_category;

        typedef typename ft::conditional<B, const value_type&, value_type&>::type reference;
        typedef typename ft::conditional<B, const value_type*, value_type*>::type pointer;

        mapIteratorReverse(void) : _is_gost(false), node(NULL), _alloc(std::allocator<Node<value_type> >()){};
        mapIteratorReverse(node_pointer ptr) : _is_gost(false), _alloc(std::allocator<Node<value_type> >()) {node = ptr;};

        template <bool B1>
        mapIteratorReverse(mapIteratorReverse<pair, B1> const &src) : _alloc(std::allocator<ft::Node<value_type> >())
        {
            _is_gost = src.getGost();
            node = src.getNode();
        };

        template <bool B1>
        mapIteratorReverse(ft::mapIterator<pair, B1> const &src) : _alloc(std::allocator<ft::Node<value_type> >())
        {
            _is_gost = src.getGost();
            node = src.getNode();
        };



        virtual ~mapIteratorReverse()
        {       
        };

        mapIteratorReverse &operator=(mapIteratorReverse const &src) 
        {
            _is_gost = src._is_gost;
            node = src.node;
            return (*this);
        };

        // INCREMENTERS
        mapIteratorReverse &operator --() 
        {
            if (node)
            {
                if (_is_gost)
                {
                    node = node->parent;
                    _is_gost = false;
                    return (*this);
                }
                if (_is_the_last(node) == node->right)
                {
                    //node_pointer gost = _alloc.allocate(1);
                    //_alloc.construct(gost, node_type());
                    //gost->parent = node;
                    _is_gost = true;
                    node = node->right;
                    return (*this);
                }
                if (node->right)
                    node = _smallest(node->right);
                else
                {
                    if (node->parent && node->parent->right && node == node->parent->right)
                    {
                        while (node->parent && node->parent->right  && node == node->parent->right)
                            node = node->parent;
                    }
                    node = node->parent;
                }
            } 
            return (*this);
        };// ++a
        
        
        mapIteratorReverse operator ++(int)
        {
            mapIteratorReverse temp = *this;
            ++(*this);
            return (temp);
        };// a++

        mapIteratorReverse operator+(int n)
        {
            while (n--)
                ++(*this);
            return (*this);
        };

        
        mapIteratorReverse &operator ++()
        {
            if (node)
            {
                if (_is_gost)
                {
                    node = node->parent;
                    _is_gost = false;
                    return (*this);
                }
                if (_is_the_first(node) == node)
                {
                    //node_pointer gost = _alloc.allocate(1);
                    //_alloc.construct(gost, node_type());
                    //gost->parent = _is_the_last(node);
                    _is_gost = true;
                    this->node = _is_the_last(node);;
                    return (*this);
                }
                if (node->left)
                    node = _biggest(node->left);
                else
                {
                    if (node->parent && node->parent->left && node == node->parent->left)
                    {
                        while (node->parent && node->parent->left && node == node->parent->left)
                            node = node->parent;
                    }
                    node = node->parent;
                }
            }
            return (*this);
        };// --a

        
        mapIteratorReverse operator --(int)
        {
            mapIteratorReverse temp = *this;
            --(*this);
            return (temp);
        };	// a--


        mapIteratorReverse operator-(int n)
        {
            while (n--)
                --(*this);
            return (*this);
        };

        //DEREFERENCING & ADDRESS STUFF
        const_pointer           operator->() const {return (&(this->operator*()));};
        pointer                 operator->()  {return (&(this->operator*()));};
        reference               operator*() {return (mapIteratorReverse(*this) + 1).getNode()->data;};
        const_reference         operator*() const {return (mapIteratorReverse(*this) + 1).getNode()->data;};
        
        node_pointer getNode() const {return (node);};
        bool         getGost() const {return (_is_gost);};
        mapIterator<pair, B>  base() const {return (mapIterator<pair, B>(node));};

        static const bool input_iter = true;
        /*friend mapIteratorReverse	operator+(difference_type n, const mapIteratorReverse &rhs)
		{ return rhs.operator+(n); };*/

        void    set_is_gost(bool a){_is_gost = a;};

        protected:
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
            
            bool                                    _is_gost;
            node_pointer                            node;
            std::allocator<Node<value_type> >       _alloc;
    };

    template<class T1, bool B1, class T2, bool B2>
    bool operator==(const  mapIteratorReverse<T1,  B1>& lhs, const  mapIteratorReverse<T2, B2>& rhs)
    {
        if (!lhs.getNode())
            return (true);
        if (lhs.getGost() && rhs.getGost())
            return (true);
        if (lhs.getGost() || rhs.getGost())
            return (false);
        return (*(lhs.getNode())) == *(rhs.getNode());
    };

    template<class T1,  bool B1, class T2, bool B2>
    bool operator!=( const  mapIteratorReverse<T1, B1>& lhs, const  mapIteratorReverse<T2, B2>& rhs){return (!(lhs == rhs));};
}

#endif

   
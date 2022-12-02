/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setIteratorReverseReverseReverse.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:43 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/15 12:11:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_REVERSE_HPP
#define SET_ITERATOR_REVERSE_HPP
#include "../../utils/iterator_traits.hpp"
#include "../../utils/utils.h"
#include "setIterator.hpp"




namespace ft
{  
    template < class Key, bool B = false >
    class	setIteratorReverse
    {
    public:
        
        typedef Key                                value_type;
        typedef Node<Key>                          node_type;
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

        setIteratorReverse(void) : _is_gost(false), node(NULL), _alloc(std::allocator<Node<value_type> >()){};
        setIteratorReverse(node_pointer ptr) : _is_gost(false), _alloc(std::allocator<Node<value_type> >()) {node = ptr;};

        template <bool B1>
        setIteratorReverse(setIteratorReverse<Key, B1> const &src) : _alloc(std::allocator<ft::Node<value_type> >())
        {
            _is_gost = src.getGost();
            node = src.getNode();
        };

        template <bool B1>
        setIteratorReverse(ft::setIterator<Key, B1> const &src) : _alloc(std::allocator<ft::Node<value_type> >())
        {
            _is_gost = src.getGost();
            node = src.getNode();
        };



        virtual ~setIteratorReverse()
        {       
        };

        setIteratorReverse &operator=(setIteratorReverse const &src) 
        {
            _is_gost = src._is_gost;
            node = src.node;
            return (*this);
        };

        // INCREMENTERS
        setIteratorReverse &operator --() 
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
        
        
        setIteratorReverse operator ++(int)
        {
            setIteratorReverse temp = *this;
            ++(*this);
            return (temp);
        };// a++

        setIteratorReverse operator+(int n)
        {
            while (n--)
                ++(*this);
            return (*this);
        };

        
        setIteratorReverse &operator ++()
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

        
        setIteratorReverse operator --(int)
        {
            setIteratorReverse temp = *this;
            --(*this);
            return (temp);
        };	// a--


        setIteratorReverse operator-(int n)
        {
            while (n--)
                --(*this);
            return (*this);
        };

        //DEREFERENCING & ADDRESS STUFF
        const_pointer           operator->() const {return (&(this->operator*()));};
        //pointer                 operator->()  {return (&(this->operator*()));};
        //reference               operator*() {return (setIteratorReverse(*this) + 1).getNode()->data;};
        const_reference         operator*() const {return (setIteratorReverse(*this) + 1).getNode()->data;};
        
        node_pointer getNode() const {return (node);};
        bool         getGost() const {return (_is_gost);};
        setIterator<Key, B>  base() const {return (setIterator<Key, B>(node));};

        static const bool input_iter = true;
        /*friend setIteratorReverse	operator+(difference_type n, const setIteratorReverse &rhs)
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
    bool operator==(const  setIteratorReverse<T1,  B1>& lhs, const  setIteratorReverse<T2, B2>& rhs)
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
    bool operator!=( const  setIteratorReverse<T1, B1>& lhs, const  setIteratorReverse<T2, B2>& rhs){return (!(lhs == rhs));};
}

#endif

   
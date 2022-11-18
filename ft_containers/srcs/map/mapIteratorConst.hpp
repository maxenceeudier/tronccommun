/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIteratorConst.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:48 by meudier           #+#    #+#             */
/*   Updated: 2022/11/18 16:30:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORCONST_HPP
# define MAPITERATORCONST_HPP
#include "../../utils/iterator_traits.hpp"
#include "../../utils/utils.h"
#include "./mapIterator.hpp"
//#include "../../Include/include.h"

namespace ft
{

    template < class pair, class Allocator = std::allocator<ft::Node<pair> > >
    class	mapIteratorConst
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

        mapIteratorConst(void) : _is_gost(false), _alloc(Allocator()) {};
        mapIteratorConst(node_pointer ptr) : _is_gost(false), _alloc(Allocator()) {node = ptr;};
        mapIteratorConst(node_const_pointer ptr) : _is_gost(false) {node = ptr;};
        mapIteratorConst(mapIteratorConst const &src): _is_gost(src._is_gost), _alloc(Allocator())
        {
            if (this->_is_gost)
            {
                node = _alloc.allocate(1);
                _alloc.construct(node, node_type(*(src.node)));
            }
            else
                node = src.node;
        };

        virtual ~mapIteratorConst()
        {
            if (_is_gost)
            {
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
                
        };

        mapIteratorConst &operator=(mapIteratorConst const &src) 
        {
            
            if (_is_gost)
            {
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
            _alloc = src._alloc;
            _is_gost = src._is_gost;
            if (this->_is_gost)
            {
                node = _alloc.allocate(1);
                _alloc.construct(node, node_type(*(src.node)));
            }
            else
                node = src.node;
            return (*this);
        };

        // INCREMENTERS
        mapIteratorConst operator ++() 
        {
            if (node)
            {
                if (_is_gost)
                {
                    node_pointer temp = node->parent;
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                    node = temp;
                    _is_gost = false;
                    return (*this);
                }
                if (_is_the_last(node) == node)
                {
                    node_pointer gost = _alloc.allocate(1);
                    _alloc.construct(gost, node_type());
                    gost->parent = node;
                    _is_gost = true;
                    node = gost;
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
        
        
        mapIteratorConst operator ++(int)
        {
            mapIteratorConst temp = *this;
            ++(*this);
            return (temp);
        };// a++

        mapIteratorConst operator+(int n)
        {
            while (n--)
                ++(*this);
            return (*this);
        };

        
        mapIteratorConst operator --()
        {
            if (node)
            {
                if (_is_gost)
                {
                    node_pointer temp = node->parent;
                    _alloc.destroy(node);
                    _alloc.deallocate(node, 1);
                    node = temp;
                    _is_gost = false;
                    return (*this);
                }
                if (_is_the_first(node) == node)
                {
                    node_pointer gost = _alloc.allocate(1);
                    _alloc.construct(gost, node_type());
                    gost->parent = _is_the_last(node);
                    _is_gost = true;
                    this->node = gost;
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

        
        mapIteratorConst operator --(int)
        {
            mapIteratorConst temp = *this;
            --(*this);
            return (temp);
        };	// a--


        mapIteratorConst operator-(int n)
        {
            while (n--)
                --(*this);
            return (*this);
        };

        //DEREFERENCING & ADDRESS STUFF
        pointer           operator->(){return (&(node->data));};
        reference         operator*(){return ((node->data));};
        
        node_pointer getNode() const {return (node);}
        bool         getGost() const {return (_is_gost);}

        template< class T1, class T2>
        friend bool operator==( const ft::mapIteratorConst< T1> & lhs, const ft::mapIteratorConst<T2> & rhs );

        template< class T1, class T2>
        friend bool operator==( const ft::mapIteratorConst< T1> & lhs, const ft::mapIterator<T2> & rhs );
        
        static const bool input_iter = true;

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
            
            bool                    _is_gost;
            node_pointer      node;
            Allocator               _alloc;
    };

    template<class T1, class T2>
    bool operator==(const  mapIteratorConst<T1>& lhs, const  mapIteratorConst<T2>& rhs)
    {
        if (!lhs.getNode())
            return (true);
        if (lhs.getGost() && rhs.getGost())
            return (true);
        if (lhs.getGost() || rhs.getGost())
            return (false);
        return (*(lhs.getNode())) == *(rhs.getNode());
    };

       
    template<class T1, class T2>
    bool operator!=( const  mapIteratorConst<T1>& lhs, const  mapIteratorConst<T2>& rhs){return (!(lhs == rhs));};


    template<class T1, class T2>
    bool operator==(const  mapIteratorConst<T1>& lhs, const  mapIterator<T2>& rhs)
    {
        if (!lhs.getNode())
            return (true);
        if (lhs.getGost() && rhs.getGost())
            return (true);
        if (lhs.getGost() || rhs.getGost())
            return (false);
        return (*(lhs.getNode())) == *(rhs.getNode());
    };

       
    template<class T1, class T2>
    bool operator!=( const  mapIteratorConst<T1>& lhs, const  mapIterator<T2>& rhs){return (!(lhs == rhs));};
}
#endif
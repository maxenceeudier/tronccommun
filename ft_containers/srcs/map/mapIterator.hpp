/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:22:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/21 17:31:22 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
#include "../../utils/iterator_traits.hpp"
#include "../../utils/utils.h"
//#include "../../Include/include.h"

namespace ft
{

    template < class pair, class Allocator = std::allocator<ft::Node<pair> > >
    class	mapIterator
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

        mapIterator(void) : _is_gost(false), _alloc(Allocator()) {};
        mapIterator(node_pointer ptr) : _is_gost(false), _alloc(Allocator()) {node = ptr;};

        /*template <class T1, class Allocator1>
        mapIterator(mapIterator<T1, Allocator1> const &src) : _is_gost(src.getGost()), _alloc(Allocator1())
        {
            if (this->_is_gost)
            {
                node = _alloc.allocate(1);
                _alloc.construct(node, node_type(*(src.getNode())));
            }
            else
                node = src.node;
        };*/

        
        mapIterator(mapIterator const &src): _is_gost(src._is_gost), _alloc(Allocator())
        {
            if (this->_is_gost)
            {
                node = _alloc.allocate(1);
                _alloc.construct(node, node_type(*(src.node)));
            }
            else
                node = src.node;
        };

        virtual ~mapIterator()
        {
            if (_is_gost)
            {
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
                
        };

        template < class pair2, class Allocator2  >
        mapIterator &operator=(mapIterator<pair2, Allocator2> const &src)
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
        }

        /*mapIterator &operator=(mapIterator const &src) 
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
        };*/

        // INCREMENTERS
        mapIterator operator ++() 
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
        
        
        mapIterator operator ++(int)
        {
            mapIterator temp = *this;
            ++(*this);
            return (temp);
        };// a++

        mapIterator operator+(int n)
        {
            while (n--)
                ++(*this);
            return (*this);
        };

        
        mapIterator operator --()
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

        
        mapIterator operator --(int)
        {
            mapIterator temp = *this;
            --(*this);
            return (temp);
        };	// a--


        mapIterator operator-(int n)
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
        friend bool operator==( const ft::mapIterator< T1> & lhs, const ft::mapIterator<T2> & rhs );

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
            
            bool            _is_gost;
            node_pointer    node;
            Allocator       _alloc;
    };

    template<class T1, class T2>
    bool operator==(const  mapIterator<T1>& lhs, const  mapIterator<T2>& rhs)
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
    bool operator!=( const  mapIterator<T1>& lhs, const  mapIterator<T2>& rhs){return (!(lhs == rhs));};

}
#endif
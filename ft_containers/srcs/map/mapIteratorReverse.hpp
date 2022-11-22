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
//#include "../../Include/include.h"

namespace ft
{
    /*template < class pair, class Allocator = std::allocator<ft::Node<pair> > >
    class	mapIteratorReverseReverse
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

        mapIteratorReverseReverse(void) : _is_gost(false) {};
        mapIteratorReverseReverse(node_pointer ptr) : _is_gost(false), _alloc(Allocator()) {node = ptr;};
        mapIteratorReverseReverse(node_const_pointer ptr) : _is_gost(false), _alloc(Allocator()) {node = ptr;};
        mapIteratorReverseReverse(mapIteratorReverseReverse const &src): _is_gost(src._is_gost), _alloc(Allocator())
        {
            if (this->_is_gost)
            {
                node = _alloc.allocate(1);
                _alloc.construct(node, node_type(*(src.node)));
            }
            else
                node = src.node;
        };

        virtual ~mapIteratorReverseReverse()
        {
            if (_is_gost)
            {
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
        };

        mapIteratorReverseReverse &operator=(mapIteratorReverseReverse const &src) 
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
        mapIteratorReverseReverse operator --() 
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
                    if (node->parent && node->parent->right && *node == node->parent->right)
                    {
                        while (node->parent && node->parent->right && *node == node->parent->right)
                            node = node->parent;
                    }
                    node = node->parent;
                }
            } 
            return (*this);
        };// ++a
        
        
        mapIteratorReverseReverse operator --(int)
        {
            mapIteratorReverseReverse temp = *this;
            --(*this);
            return (temp);
        };// a++


        mapIteratorReverseReverse operator-(int n)
        {
            while (n--)
                --(*this);
            return (*this);
        };

        
        mapIteratorReverseReverse operator ++()
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

        
        mapIteratorReverseReverse operator ++(int)
        {
            mapIteratorReverseReverse temp = *this;
            ++(*this);
            return (temp);
        };	// a--


        mapIteratorReverseReverse operator+(int n)
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
            Allocator       _alloc;
    };

    template< class T1>
    bool operator==( const ft::mapIteratorReverseReverse< T1> & lhs, \
    const ft::mapIteratorReverseReverse<T1> & rhs )
    {return (*(lhs.operator->()) == *(rhs.operator->()));};

    template<class T1>
    bool operator!=( const ft::mapIteratorReverseReverse< T1> & lhs, \
    const ft::mapIteratorReverseReverse<T1>& rhs ){return (!(lhs == rhs));};*/



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

        mapIteratorReverse(void) : _is_gost(false), _alloc(std::allocator<Node<value_type> >()), node(NULL){};
        mapIteratorReverse(node_pointer ptr) : _is_gost(false), _alloc(std::allocator<Node<value_type> >()) {node = ptr;};

        template <bool B1>
        mapIteratorReverse(mapIteratorReverse<pair, B1> const &src) : _alloc(std::allocator<ft::Node<value_type> >())
        {
            _is_gost = src.getGost();
            node = src.getNode();
        };



        virtual ~mapIteratorReverse()
        {
            if (_is_gost)
            {
                //delete node;
            }
                
        };

        mapIteratorReverse &operator=(mapIteratorReverse const &src) 
        {
            _is_gost = src._is_gost;
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
        pointer           operator->(){return (&(node->data));};
        reference         operator*(){return ((node->data));};
        
        node_pointer getNode() const {return (node);};
        bool         getGost() const {return (_is_gost);};

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

   
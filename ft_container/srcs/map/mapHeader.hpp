/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapHeader.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:01:50 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:20:51 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAPHEADER_HPP
#define MAPHEADER_HPP
#include <memory>
#include "../../utils/RBTree_impl.hpp"
#include "../../utils/iterator_traits.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/distance.hpp"
#include "../../utils/reverse_iterator.hpp"
#include "../../utils/swap.hpp"
#include "mapIterator.hpp"
#include "mapIteratorReverse.hpp"
//#include "../../Include/include.h"


namespace ft
{
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
    class map : public ft::RBTree<ft::pair<Key, T>, typename Allocator::template rebind<ft::Node<ft::pair<Key, T> > >::other >
    {
        public:
            class ValueCompare;
        
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef ft::pair<Key, T>                            value_type;
            typedef ft::Node<value_type>                        node_type;
            typedef std::size_t                                 size_type;
            typedef std::ptrdiff_t                              difference_type;
            typedef Compare                                     key_compare;
            typedef ValueCompare                                value_compare;
            typedef	Allocator                                   allocator_type;
            typedef	value_type&                                 reference;
            typedef	const value_type&                           const_reference;
            typedef typename Allocator::pointer                 pointer;
            typedef typename Allocator::const_pointer           const_pointer;
            typedef ft::mapIterator< value_type >               iterator;
            typedef ft::mapIterator< value_type , true>         const_iterator;
            typedef	ft::mapIteratorReverse<value_type>          reverse_iterator;
            typedef ft::mapIteratorReverse<value_type,  true>   const_reverse_iterator;

            typedef typename Allocator::template rebind<ft::Node<value_type> >::other  AllocNode;
            
            typedef ft::RBTree<ft::pair< Key, T>,  typename allocator_type::template rebind<ft::Node<value_type> >::other, ValueCompare >    RBTree;

            template <class T1, class T2, class T3, class T4>
            friend std::ostream	&operator<<(std::ostream &o, ft::map<T1, T2, T3, T4> &map);
            
            friend class ValueCompare;
            

        protected:
            key_compare         _comp;
            allocator_type      _alloc;
            RBTree              _tree;
            Node<value_type>    *_gost;
            AllocNode           _allocNode;

        public:
            /*----------------------------------*/
            /*           basic function         */
            /*----------------------------------*/
            
            map();
            explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
            
            template< class InputIt >
            map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator(), \
            typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true) : _comp(comp), _alloc(alloc)
            {
                _gost = _allocNode.allocate(1);
                _allocNode.construct(_gost, Node<value_type>());

                insert(first, last);
            };
            
            map( const map& other );
            
            ~map();

            map& operator=( const map& other );

            allocator_type get_allocator() const;

            /*----------------------------------*/
            /*           access elements        */
            /*----------------------------------*/

            T& at( const Key& key );

            const T& at( const Key& key ) const;

            T& operator[]( const Key& key );

            /*----------------------------------*/
            /*           iterators              */
            /*----------------------------------*/
            
            /*-------begin*/
            iterator begin();
            const_iterator begin() const;

            /*--------end*/
            iterator end();
            const_iterator end() const;

            /*--------rbegin*/
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;

            /*--------rend*/
            reverse_iterator rend();
            const_reverse_iterator rend() const;

            /*----------------------------------*/
            /*           capacity               */
            /*----------------------------------*/
            bool empty() const;

            size_type size() const;

            size_type max_size() const;

            /*----------------------------------*/
            /*           modifiers              */
            /*----------------------------------*/

            void clear();

            ft::pair<iterator, bool> insert( const value_type& value );

            iterator insert( iterator hint, const value_type& value );
            
            template< class InputIt >
            void insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true)
            {
                while (first != last)
                {
                    if (this->find(first->first) == this->end())
                    {
                        if (_gost->parent)
                            _gost->parent->right = NULL;
                            
                        _tree.insertValue(*(first));

                        _gost->parent = _tree.maxValueNode(_tree.getRoot());
                        if (_gost->parent)
                            _gost->parent->right = _gost;
                    }
                    first++;
                }
            };

            void erase( iterator pos );
            void erase( iterator first, iterator last );
            size_type erase( const Key& key );

            void swap( map& other );

            /*----------------------------------*/
            /*           lookup                 */
            /*----------------------------------*/

            size_type count( const Key& key ) const;

            iterator find( const Key& key );
            
            const_iterator find( const Key& key ) const;

            
            pair<iterator,iterator> equal_range( const Key& key );
            pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
            
            iterator lower_bound( const Key& key );
            const_iterator lower_bound( const Key& key ) const;

            iterator upper_bound( const Key& key );
            const_iterator upper_bound( const Key& key ) const;

            /*----------------------------------*/
            /*           observers              */
            /*----------------------------------*/

            key_compare key_comp() const;

            value_compare value_comp() const;
            
            /*----------------------------------*/
            /*           member_class           */
            /*----------------------------------*/ 
            
            class ValueCompare
            {
                protected:
                    Compare   comp;
                    ValueCompare(Compare c): comp(c){};
                public:
                    friend class map;
                    typedef bool        result_type;
                    typedef value_type  first_argument_type;
                    typedef value_type  second_argument_type;

                    ValueCompare(void)
                    {
                        comp = Compare();
                    }
                    bool operator()( const value_type& lhs, const value_type& rhs ) const
                    {return (comp(lhs.first, rhs.first));};       
            };

            
    };
}

template< class Key1, class T1 , class Allocator1, class Compare1>
void    swap(ft::map<Key1, T1, Compare1, Allocator1>& lhs, ft::map<Key1,T1, Compare1, Allocator1>& rhs )
{
    lhs.swap(rhs);
};

#endif
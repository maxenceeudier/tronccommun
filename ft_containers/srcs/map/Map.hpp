/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:01:50 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 15:53:55 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include "../../utils/RBTree_impl.hpp"
#include "../../utils/iterator_traits.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/distance.hpp"
#include "../../utils/reverse_iterator.hpp"
#include "mapIterator.hpp"

namespace ft
{
    template< 
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<ft::pair<const Key, T> > 
    >
    class map
    {
        public:
            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef ft::pair<const Key, T>                  value_type;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef Compare                                 key_compare;
            typedef	Allocator                               allocator_type;
            typedef	value_type&                             reference;
            typedef	const value_type&                       const_reference;
            typedef Allocator::pointer                      pointer;
            typedef Allocator::const_pointer                const_pointer;
            typedef ft::mapIterator<value_type>             iterator;
            typedef ft::mapIterator<const value_type>       const_iterator;
            typedef	std::reverse_iterator<iterator>         reverse_iterator;
            typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;
            typedef ft::RBTree<ft::pair<const Key, T> >     RBTree;
            
        protected:
            key_compare     _comp;
            allocator_type  _alloc;
            RBTree          _tree;

        public:
            /*----------------------------------*/
            /*           basic function         */
            /*----------------------------------*/
            map();
            explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
            template< class InputIt >
            map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
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
            void insert( InputIt first, InputIt last );

            iterator erase( iterator pos );
            iterator erase( iterator first, iterator last );
            size_type erase( const Key& key );

            void swap( map& other );

            /*----------------------------------*/
            /*           lookup                 */
            /*----------------------------------*/

            size_type count( const Key& key ) const;

            iterator find( const Key& key );
            const_iterator find( const Key& key ) const;

            std::pair<iterator,iterator> equal_range( const Key& key );
            std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

            iterator lower_bound( const Key& key );
            const_iterator lower_bound( const Key& key ) const;

            iterator upper_bound( const Key& key );
            const_iterator upper_bound( const Key& key ) const;

            /*----------------------------------*/
            /*           observers              */
            /*----------------------------------*/

            key_compare key_comp() const;

            std::map::value_compare value_comp() const;          
    };
}
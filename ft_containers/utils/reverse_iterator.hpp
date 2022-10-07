/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:43 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/07 17:17:00 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

namespace ft
{
    template< class Iter >
    class reverse_iterator
    {
        public:
            typedef Iter                                iterator_type;
            typedef typename Iter::value_type           value_type;
            typedef typename Iter::difference_type      difference_type;
            typedef typename Iter::pointer              pointer;
            typedef typename Iter::const_pointer        const_pointer;
            typedef typename Iter::reference            reference;
            typedef typename Iter::const_reference      const_reference;

            
            reverse_iterator(void) {};
            explicit reverse_iterator(Iter x){_ptr = x.operator->();};
            template< class U >
            reverse_iterator(const reverse_iterator<U>& other) {*this = other;};
            reverse_iterator(pointer ptr) {_ptr = ptr;};

            virtual     ~reverse_iterator() {};

            reverse_iterator &operator= (reverse_iterator const &src) {_ptr = src.operator->(); return (*this); };

            // ARITHMETICS
            reverse_iterator operator +(difference_type b) {return (reverse_iterator(_ptr - b));}; // a + n
            reverse_iterator operator -(difference_type b) {return (reverse_iterator(_ptr + b));}; // a - n

            difference_type operator +(reverse_iterator b) {return (_ptr - b._ptr); }; // a + b
            difference_type operator -(reverse_iterator b) {return (_ptr + b._ptr); }; // a - b

            // INCREMENTERS
            reverse_iterator operator ++() {_ptr--; return (*this);};			// ++a
            reverse_iterator operator ++(int) {_ptr--; return (reverse_iterator(_ptr - 1));};	// a++
            reverse_iterator operator --() {_ptr++; return (*this);};			// --a
            reverse_iterator operator --(int) {_ptr++; return (reverse_iterator(_ptr + 1));};	// a--

            //COMPOUND ASSIGNMENTS
            void operator +=(difference_type b) {_ptr -= b;};	// a += b
            void operator -=(difference_type b) {_ptr += b;};	// a -= b

            //DEREFERENCING & ADDRESS STUFF
            reference operator*(){ return (*_ptr); };											// *a
            const_reference operator*() const {return (*_ptr);};								// *a
            reference operator [](difference_type b) {return (*(_ptr + b));};					// a[]
            const_reference operator [](difference_type b) const {return (*(_ptr + b));};		// a[]
            pointer operator ->(){return (_ptr);};											// a->b
            const_pointer operator ->() const {return (_ptr);};											// a->b

            static const bool input_iter = true;

        private:
            pointer _ptr;
    };

    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::reverse_iterator<Iterator1>& lhs, \
    const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.operator->() == rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs, \
    const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.operator->() < rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::reverse_iterator<Iterator1>& lhs, \
    const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.operator->() > rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, \
    const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.operator->() <= rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, \
    const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.operator->() >= rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, \
    const ft::reverse_iterator<Iterator2>& rhs ){return (lhs.operator->() != rhs.operator->());};

}


   
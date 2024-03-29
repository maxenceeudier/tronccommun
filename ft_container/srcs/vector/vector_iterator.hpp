/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:38:00 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:31:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP
# include "../../utils/iterator_traits.hpp"
# include "../../utils/conditional.hpp"
# include "../../utils/enable_if.hpp"
# include <iostream>

namespace ft
{

    template <bool B, typename T>
    class	vectorIterator
    {
    public:

        typedef typename ft::conditional<B, T, const T>::type   value_type;
        typedef value_type&				                        reference;
        typedef const value_type&		                        const_reference;
        typedef value_type*				                        pointer;
        typedef const value_type*		                        const_pointer;
        typedef typename std::ptrdiff_t                         difference_type;
        typedef ft::random_access_iterator_tag                  iterator_category;

        vectorIterator(void) : _ptr(NULL) {};
        vectorIterator(pointer ptr) {_ptr = ptr;};

        template <bool B2>
        vectorIterator(const vectorIterator<B2, T> & x, typename ft::enable_if<B2>::type* = 0)
        {       
            _ptr = x.operator->();
        };
    
        virtual ~vectorIterator() {};

        vectorIterator &operator=(vectorIterator const &src) {_ptr = src.getPtr(); return (*this); };

        // ARITHMETICS
        vectorIterator operator +(difference_type b) const {return (vectorIterator(_ptr + b));}; // a + n
        vectorIterator operator -(difference_type b) const {return (vectorIterator(_ptr - b));}; // a - n

        template < bool B1>
        difference_type operator +(vectorIterator<B1, T> b) const {return (_ptr + b.getPtr()); }; // a + b
        
        template < bool B1>
        difference_type operator -(vectorIterator<B1, T> b) const {return (_ptr - b.getPtr()); }; // a - b

        // INCREMENTERS
        vectorIterator &operator ++() {++_ptr; return (*this);};			// ++a
        vectorIterator operator ++(int) {++_ptr; return (vectorIterator(_ptr - 1));};	// a++
        vectorIterator &operator --() {--_ptr; return (*this);};			// --a
        vectorIterator operator --(int) {--_ptr; return (vectorIterator(_ptr + 1));};	// a--

        //COMPOUND ASSIGNMENTS
        vectorIterator &operator +=(difference_type b) {_ptr += b; return (*this);};	// a += b
        vectorIterator &operator -=(difference_type b) {_ptr -= b; return (*this);};	// a -= b

        friend vectorIterator	operator+	(int n, const vectorIterator & x)		{ return (x.getPtr() + n); }
        //DEREFERENCING & ADDRESS STUFF
        reference operator*(){ return (*_ptr); };											// *a
        const_reference operator*() const {return (*_ptr);};								// *a
        reference operator [](difference_type b) {return (*(_ptr + b));};					// a[]
        const_reference operator [](difference_type b) const {return (*(_ptr + b));};		// a[]
        pointer operator->(){return (_ptr);};											    // a->b
        const_pointer operator->() const {return (_ptr);};										// a->b

        value_type *			getPtr		(void) const							{ return (_ptr); }

        //comparator
        template< bool B2, typename T2 >
        bool operator==( const vectorIterator<B2, T2>& rhs) const {return (this->_ptr == rhs.operator->());};

        template< bool B2, typename T2 >
        bool operator!=( const vectorIterator<B2, T2>& rhs) const {return (this->_ptr != rhs.operator->());};

        template< bool B2, typename T2 >
        bool operator>( const vectorIterator<B2, T2>& rhs) const {return (this->_ptr > rhs.operator->());};

        template< bool B2, typename T2 >
        bool operator>=( const vectorIterator<B2, T2>& rhs) const {return (this->_ptr >= rhs.operator->());};

        template< bool B2, typename T2 >
        bool operator<( const vectorIterator<B2, T2>& rhs) const {return (this->_ptr < rhs.operator->());};
        
        template< bool B2, typename T2 >
        bool operator<=( const vectorIterator<B2, T2>& rhs) const {return (this->_ptr <= rhs.operator->());};
        
        static const bool input_iter = true;

        private:
            pointer _ptr;
    };
}
#endif


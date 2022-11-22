/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:43 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/21 16:32:24 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	/*==============================*/
	/*      Reverse iterator        */
	/*==============================*/

	template <class it>
	class reverse_iterator {
	public:
        typedef typename ft::iterator_traits<it>::value_type      value_type;
        typedef typename ft::iterator_traits<it>::difference_type difference_type;
        typedef typename ft::iterator_traits<it>::pointer         pointer;
        typedef typename it::const_pointer                        const_pointer;
        typedef typename ft::iterator_traits<it>::reference       reference;
        typedef typename it::const_reference                      const_reference;
    
		// -structors
		reverse_iterator			(void)												{ _it = it(); }
		reverse_iterator			(typename it::value_type * ptr)						{ _it = it(ptr); }
		reverse_iterator			(const it & x)										{ _it = x; --_it; }
		~reverse_iterator			(void)												{}
		// Conversion
		template <class U>			friend class										reverse_iterator;
		template <class U>
		reverse_iterator			(const reverse_iterator<U> & x)						{ _it = x.getIt(); }

		// Assignment
		reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIt(); return (*this); }
		reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
		reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
		// Comparison
		template <class U> bool		operator==	(const reverse_iterator<U> & x) const	{ return (_it == x.getIt()); }
		template <class U> bool		operator!=	(const reverse_iterator<U> & x) const	{ return (_it != x.getIt()); }
		template <class U> bool		operator<	(const reverse_iterator<U> & x) const	{ return (_it > x.getIt()); }
		template <class U> bool		operator>	(const reverse_iterator<U> & x) const	{ return (_it < x.getIt()); }
		template <class U> bool		operator<=	(const reverse_iterator<U> & x) const	{ return (_it >= x.getIt()); }
		template <class U> bool		operator>=	(const reverse_iterator<U> & x) const	{ return (_it <= x.getIt()); }
		// -crementation
		reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
		reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
		reverse_iterator			operator++	(int)									{ reverse_iterator<it> x(*this); --_it; return (x); }
		reverse_iterator			operator--	(int)									{ reverse_iterator<it> x(*this); ++_it; return (x); }
		// Operation
		reverse_iterator			operator+	(difference_type n) const				{ return (_it - n); }
		reverse_iterator			operator-	(difference_type n) const				{ return (_it + n); }
		std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIt() - _it); }
		// Dereference
		

        reference operator*(){ return (*_it); };											// *a
        const_reference operator*() const {return (*_it);};								    // *a
        reference operator [](difference_type b) {return (*(_it - b));};					// a[]
        const_reference operator [](difference_type b) const {return (*(_it - b));};		// a[]
        pointer operator ->(){return (&(*_it));};											// a->b
        const_pointer operator ->() const {return (&(*_it));}	    						// a->b

		// Member functions
		it							getIt		(void) const							{ return (_it); }
        void                        set_is_gost(bool a){_it.set_is_gost(a);};

        static const bool input_iter = true;

	private:
		it		_it;
	};
}

#endif

   
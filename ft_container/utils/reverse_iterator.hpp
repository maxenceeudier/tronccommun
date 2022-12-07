/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:43 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/01 11:17:54 by maxenceeudi      ###   ########.fr       */
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

	template <class It>
	class reverse_iterator
	{
		protected:
			It _it;
		public:
			typedef typename ft::iterator_traits<It>::value_type      value_type;
			typedef typename ft::iterator_traits<It>::difference_type difference_type;
			typedef typename ft::iterator_traits<It>::pointer         pointer;
			typedef typename It::const_pointer                        const_pointer;
			typedef typename ft::iterator_traits<It>::reference       reference;
			typedef typename It::const_reference                      const_reference;

		reverse_iterator(void): _it() { };
		explicit reverse_iterator(It x) : _it(x) { };
	
		~reverse_iterator(){};
		
		template <class U>
		reverse_iterator(const reverse_iterator<U> &u): _it(u.base()) { };
		
		template <class U>
		reverse_iterator &operator=(const reverse_iterator<U> &u)
		{
			this->_it = u.base();
			return (*this);
		};

		
		It base(void) const { return this->_it; };

		reference			operator*(void) const { return (*(_it - 1));};
		pointer				operator->(void) const { return &this->operator*(); };

		reverse_iterator	&operator++(void) { --_it; return *this; };
		reverse_iterator	operator++(int) { reverse_iterator temp(*this); --_it; return(temp); };
		reverse_iterator	&operator--(void) { ++_it; return *this; };
		reverse_iterator	operator--(int) { reverse_iterator temp(*this); ++_it; return(temp); };

		template <class U>
		difference_type		operator-(const reverse_iterator<U> &u) { return u.base().operator-(this->_it); };

		reverse_iterator	operator+ (difference_type n) const { return (reverse_iterator(this->_it.operator-(n)));};
		reverse_iterator	&operator+=(difference_type n) { this->_it.operator-=(n); return *this; };
		reverse_iterator	operator- (difference_type n) const { return (reverse_iterator(this->_it.operator+(n)));};
		reverse_iterator	&operator-=(difference_type n) { this->_it.operator+=(n); return *this; };
		reference			operator[](difference_type n) const { return *this->operator+(n); };

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs)
		{ return rhs.operator+(n); };

		template <class U> bool	operator==(const reverse_iterator<U> &rhs) const { return this->_it.operator==(rhs.base()); };
		template <class U> bool	operator!=(const reverse_iterator<U> &rhs) const { return this->_it.operator!=(rhs.base()); };
		template <class U> bool	operator< (const reverse_iterator<U> &rhs) const { return this->_it.operator> (rhs.base()); };
		template <class U> bool	operator<=(const reverse_iterator<U> &rhs) const { return this->_it.operator>=(rhs.base()); };
		template <class U> bool	operator> (const reverse_iterator<U> &rhs) const { return this->_it.operator< (rhs.base()); };
		template <class U> bool	operator>=(const reverse_iterator<U> &rhs) const { return this->_it.operator<=(rhs.base()); };

	};
}

#endif

   
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:22:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 15:23:17 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
#include "../../utils/iterator_traits.hpp"

namespace ft
{

    template <typename T>
    class	mapIterator
    {
    public:

        typedef T						        value_type;
        typedef value_type&				        reference;
        typedef const value_type&		        const_reference;
        typedef value_type*				        pointer;
        typedef const value_type*		        const_pointer;
        typedef typename std::ptrdiff_t         difference_type;
        typedef ft::random_access_iterator_tag  iterator_category;

        mapIterator(void) {};
        mapIterator(pointer ptr) {_ptr = ptr;};
        mapIterator(mapIterator const &src) {*this = src;} ;

        virtual ~mapIterator() {};

        mapIterator &operator=(mapIterator const &src) {_ptr = src.operator->(); return (*this); };

        // ARITHMETICS
        mapIterator operator +(difference_type b) {return (mapIterator(_ptr + b));}; // a + n
        mapIterator operator -(difference_type b) {return (mapIterator(_ptr - b));}; // a - n

        difference_type operator +(mapIterator b) {return (_ptr + b._ptr); }; // a + b
        difference_type operator -(mapIterator b) {return (_ptr - b._ptr); }; // a - b

        // INCREMENTERS
        mapIterator operator ++() {_ptr++; return (*this);};			// ++a
        mapIterator operator ++(int) {_ptr++; return (mapIterator(_ptr - 1));};	// a++
        mapIterator operator --() {_ptr--; return (*this);};			// --a
        mapIterator operator --(int) {_ptr--; return (mapIterator(_ptr + 1));};	// a--

        //COMPOUND ASSIGNMENTS
        void operator +=(difference_type b) {_ptr += b;};	// a += b
        void operator -=(difference_type b) {_ptr -= b;};	// a -= b

        //DEREFERENCING & ADDRESS STUFF
        reference operator*(){ return (*_ptr); };											// *a
        const_reference operator*() const {return (*_ptr);};								// *a
        reference operator [](difference_type b) {return (*(_ptr + b));};					// a[]
        const_reference operator [](difference_type b) const {return (*(_ptr + b));};		// a[]
        pointer operator->(){return (_ptr);};											// a->b
        pointer operator->() const {return (_ptr);};											// a->b

        static const bool input_iter = true;

        private:
            pointer _ptr;
    };

    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::mapIterator<Iterator1>& lhs, \
    const ft::mapIterator<Iterator2>& rhs ){return (lhs.operator->() == rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::mapIterator<Iterator1>& lhs, \
    const ft::mapIterator<Iterator2>& rhs ){return (lhs.operator->() > rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::mapIterator<Iterator1>& lhs, \
    const ft::mapIterator<Iterator2>& rhs ){return (lhs.operator->() < rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::mapIterator<Iterator1>& lhs, \
    const ft::mapIterator<Iterator2>& rhs ){return (lhs.operator->() >= rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::mapIterator<Iterator1>& lhs, \
    const ft::mapIterator<Iterator2>& rhs ){return (lhs.operator->() <= rhs.operator->());};

    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::mapIterator<Iterator1>& lhs, \
    const ft::mapIterator<Iterator2>& rhs ){return (lhs.operator->() != rhs.operator->());};
}
#endif
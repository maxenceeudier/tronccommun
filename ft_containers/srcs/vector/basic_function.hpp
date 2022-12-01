/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:51:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/01 13:27:15 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorHeader.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/is_integral.hpp"
#include "../../utils/distance.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template <class T, class Allocator>
    vector<T, Allocator>::vector(const Allocator& alloc)\
    : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL){}

    template <class T, class Allocator>
    vector<T, Allocator>::vector(size_type count, const T &value, const Allocator &alloc)\
    : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL)
    {this->insert(_end, count, value);}
    
    template <class T, class Allocator>
    vector<T, Allocator>::vector(const vector &cpy)\
    : _alloc(cpy.get_allocator()), _start(NULL), _end(NULL), _end_capacity(NULL)
    {*this = cpy;}
    
    template <class T, class Allocator>
    vector<T, Allocator>::~vector(void)
    {
        this->clear();
        if (this->capacity())
            _alloc.deallocate(_start, this->capacity());
    }

    

            
    template <class T, class Allocator>  
    vector<T, Allocator>  &vector<T, Allocator>::operator=(const vector &rhs)
    {
        /*if (this == &rhs)
		    return (*this);
        //this->clear();
        const_iterator first = rhs.begin();
        const_iterator last = rhs.end();
    
        vector  temp;
        size_type len = ft::distance(first, last);

        temp._alloc = this->_alloc;
        temp._start = temp._alloc.allocate(len > this->capacity() ? len : this->capacity());
        temp._end = temp._start + len;
        temp._end_capacity = temp._start + (len > this->capacity() ? len : this->capacity());
        for (size_type i = 0; first != last; ++first)
            temp._alloc.construct(&temp._start[i++], *first);
        
        this->clear();
	    this->_alloc.deallocate(this->_start, this->capacity());
	    this->_start = NULL; this->_end = NULL; this->_end_capacity = NULL;

        this->_start = temp._start;
        this->_end = temp._end;
        this->_end_capacity = temp._end_capacity;

        temp._start = NULL; temp._end = NULL; temp._end_capacity = NULL;*/

        this->clear();
        this->insert(_end, rhs.begin(), rhs.end());

        
        return (*this);
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::assign(size_type count, const T &value)
    {
        this->clear();
        this->insert(this->end(), count, value);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const
    {return (_alloc);}
}
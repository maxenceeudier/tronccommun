/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:51:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/05 17:23:26 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../../utils/enable_if.hpp"
#include "../../utils/is_integral.hpp"
#include "../../utils/distance.hpp"

namespace ft
{
    template <class T, class Allocator>
    vector<T, Allocator>::vector(const Allocator& alloc)\
    : _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr){}

    template <class T, class Allocator>
    vector<T, Allocator>::vector(size_type count, const T &value, const Allocator &alloc)\
    : _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
    {
        _start = _alloc.allocate(count);
        _end_capacity = _start + count;
        _end = _start;
        while (count--)
        {
            _alloc.constuct(_end, value);
            _end++;
        }
    }
    
    template <class T, class Allocator>
    vector<T, Allocator>::vector(const vector &cpy)\
    : _alloc(cpy.get_allocator()), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
    {*this = cpy;}
    
    template <class T, class Allocator>
    vector<T, Allocator>::~vector(void)
    {
        this->clear();
        if (this->capacity())
            _alloc.deallocate(_start, this->capacity());
    }
            
    template <class T, class Allocator>  
    vector<T, Allocator>  &vector<T, Allocator>::operator=(const vector &cpy)
    {
        if (*this == cpy)
            return (*this);
        this->clear();
        this->insert(_start, cpy.begin(), cpy.end());
        return (*this);
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::assign(size_type count, const T &value)
    {
        this->clear();
        this->insert(_start, count, value);
    }

    template <class T, class Allocator>
    vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const{return (_alloc);}
}
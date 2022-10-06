/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:21:24 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/06 17:07:44 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
namespace ft
{
    /*template <class T, class Allocator>
    vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, const T& value )
    {
    
    }*/
    
    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator pos, size_type n, const T &value )
    {
        if (!capacity())
        {
            _start = _alloc.allocate(n);
            _end_capacity = _start + n;
            _end = _start;
            while (n--)
            {
                _alloc.construct(_end, value);
                _end++;
            }
        }
        else if (pos >= _start && pos <= _end)
        {
            ft::vector<T, Allocator>    temp(pos, iterator(_end));
            int i = 0;
            int j = 0;
            while (i < ft::distance(pos + 1, iterator(_end)))
            {
                pop_back();
                i++;
            }
            while (n--)
                push_back(value);
            while (j < i)
                push_back(temp[j++]);
        }
        return (iterator(this->_end));
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::clear()
    {
        size_type  n = this->size();
        while (n--)
        {
            _alloc.destroy(_end);
            _end--;
        }
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::push_back(const T &value)
    {
        if (!_end || _end == _end_capacity)
            _double_capacity();
        _alloc.construct(_end, value);
        _end++;
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::pop_back(void)
    {
        _alloc.destroy(_end);
        _end--;
    }
    
}
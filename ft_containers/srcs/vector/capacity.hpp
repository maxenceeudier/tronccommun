/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:25:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/10 17:02:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
    {return (_end_capacity - _start);}

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
    {return (_end - _start);}

    template <class T, class Allocator>
    bool vector<T, Allocator>::empty() const
    {return (!size() ? true : false);}

    template <class T, class Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
    {return (_alloc.max_size());}

    template <class T, class Allocator>
    void vector<T, Allocator>::reserve(size_type new_cap)
    {
        if (new_cap > this->max_size())
        {
            std::string what = std::to_string(new_cap) + " can't be allocate, it's bigger than max_size (" + std::to_string(max_size()) + ")";
            throw std::length_error(what);
        } 
        if (new_cap <= this->capacity())
            return ;
        pointer new_start;
        pointer new_end;
        pointer new_end_capacity;
        pointer temp = _start;

        new_start = _alloc.allocate(new_cap);
        new_end_capacity = new_start + new_cap;
        new_end = new_start;
        while (temp != _end)
        {
            _alloc.construct(new_end, *temp);
            _alloc.destroy(temp);
            new_end++;
            temp++;
        }
        _alloc.deallocate(_start, capacity());
        _start = new_start;
        _end = new_end;
        _end_capacity = new_end_capacity;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:25:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/06 17:32:42 by maxenceeudi      ###   ########.fr       */
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
    void    vector<T, Allocator>::_double_capacity(void)
    {
        if (!capacity())
        {
            _start = _alloc.allocate(1);
            _end = _start;
            _end_capacity = _start + 1;
        }
        else
        {
            pointer new_start;
            pointer new_end;
            pointer new_end_capacity;
            pointer temp = _start;

            new_start = _alloc.allocate(capacity() * 2);
            new_end_capacity = new_start + capacity() * 2;
            new_end = new_start;
            while (temp != _end)
            {
                _alloc.construct(new_end, *temp);
                new_end++;
                temp++;
            }
            this->clear();
            _alloc.deallocate(_start, capacity());
            _start = new_start;
            _end = new_end;
            _end_capacity = new_end_capacity;
        }
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:21:24 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 14:17:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include "../../utils/swap.hpp"

namespace ft
{
    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator pos, const T& value )
    {insert(pos, 1, value);return (pos);}
    
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
        else if (pos >= iterator(_start) && pos <= iterator(_end))
        {
            
            difference_type distance = ft::distance(pos, this->end());
            ft::vector<T, Allocator>    temp(pos, this->end());
            
            if (n > capacity() - size())
            {
                reserve(size() + std::max(n, size()));
            }
               
            int i = 0;
            int j = 0;

            while (i < distance)
            {
                pop_back();
                i++;
            }
            
            while (n--)
                push_back(value);
                
            while (j < i)
                push_back(temp[j++]);
               
        }
        return (this->end());
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::clear()
    {
        size_type  n = this->size();
        while (n--)
        {
            _alloc.destroy(_end - 1);
            --_end; 
        }
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::push_back(const T &value)
    {
        if (!capacity())
            reserve(1);  
        else if (_end == _end_capacity)
            reserve(capacity() * 2);       
        _alloc.construct(_end, value);
        ++_end;
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::pop_back(void)
    {
        if (size() != 0)
        {
            _alloc.destroy(_end - 1);
            --_end;
        }   
    }
    
    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator pos )
    {
        ft::vector<T, Allocator>    temp(pos + 1, this->end());
        size_type                   n = ft::distance(pos + 1, this->end());
        size_type                   i = 0;
        
        if (pos == this->end())
            return (pos);
        while (i < n )
        {
            this->pop_back();
            i++;
        }
        this->pop_back();
        i = 0;
        while (i < n)
            this->push_back(temp[i++]);
        return (pos);
    }
    
    template <class T, class Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator first, iterator last )
    {
        size_type dist;
        if ((dist = ft::distance(first, last)) == 0)
            return (last);

        iterator temp(first);

		while (dist--)
		{
			erase(first);
		}
		return (temp);
    }

    template <class T, class Allocator>
    void vector<T, Allocator>::resize(size_type count, T value)
    {
        size_type   size = this->size() - count;
        if (count < this->size())
        {
            while (size--)
                this->pop_back();
        }
        else
        {
            while (size++)
                this->push_back(value);
        } 
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::swap(vector<T, Alloc> &other)
    {
        vector temp;
        temp._start = other._start;
        temp._end = other._end;
        temp._end_capacity = other._end_capacity;
        
        other._start = this->_start;
        other._end = this->_end;
        other._end_capacity = this->_end_capacity;
        
        this->_start = temp._start;
        this->_end = temp._end;
        this->_end_capacity = temp._end_capacity;

        temp._start = NULL;
        temp._end = NULL;
        temp._end_capacity = NULL;
    }
}
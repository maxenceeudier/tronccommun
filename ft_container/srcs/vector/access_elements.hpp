/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_elements.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:21:09 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:29:53 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
    template <class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type pos)
    {return (_start[pos]);}

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type pos) const
    {return (_start[pos]);}

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos)
    {
        if (pos >= this->size())
        {
            std::string what = "vector::_M_range_check: __n )";
            throw std::out_of_range(what);
        }
        return (_start[pos]);
        
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type pos) const
    {
        if (pos >= this->size())
        {
            std::string what = "vector::_M_range_check: __n )";
            throw std::out_of_range(what);
        }
        return (_start[pos]);
    }

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::front()
    {return (*_start);}

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
    {return (*_start);}

    template <class T, class Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::back()
    {return (*(_end - 1));}

    template <class T, class Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
    {return (*(_end - 1));}

    template <class T, class Allocator>
    typename vector<T, Allocator>::value_type* vector<T, Allocator>::data()
    {return (_start);}

    template <class T, class Allocator>
    const typename vector<T, Allocator>::value_type* vector<T, Allocator>::data() const
    {return (_start);}
}


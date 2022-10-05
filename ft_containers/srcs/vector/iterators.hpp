/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:10:39 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/05 18:08:19 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
    template <class T, class Allocator>
    vector<T, Allocator>::iterator  vector<T, Allocator>::begin()
    {
        return (iterator(_start));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::const_iterator  vector<T, Allocator>::begin() const
    {
        return (const_iterator(_start));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::iterator  vector<T, Allocator>::end()
    {
        return (iterator(_end));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::const_iterator  vector<T, Allocator>::end() const
    {
        return (const_iterator(_end));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::reverse_iterator  vector<T, Allocator>::rbegin()
    {
        return (reverse_iterator(_end));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::const_reverse_iterator  vector<T, Allocator>::rbegin() const
    {
        return (const_reverse_iterator(_end));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::reverse_iterator  vector<T, Allocator>::rend()
    {
        return (reverse_iterator(_start));
    }

    template <class T, class Allocator>
    vector<T, Allocator>::const_reverse_iterator  vector<T, Allocator>::rend() const
    {
        return (const_reverse_iterator(_start));
    }
}
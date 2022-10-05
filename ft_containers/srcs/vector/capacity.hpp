/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:25:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/05 17:36:40 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
    template <class T, class Allocator>
    vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
    {
        return (_end_capacity - _start);
    }

    template <class T, class Allocator>
    vector<T, Allocator>::size_type vector<T, Allocator>::size() const
    {
        return (_end - _start);
    }

    template <class T, class Allocator>
    bool vector<T, Allocator>::empty() const
    {
        return (!size() ? true : false);
    }

    

    
}
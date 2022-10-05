/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:21:24 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/05 17:33:50 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
    template <class T, class Allocator>
    vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, const T& value )
    {
    
    }
    
    template <class T, class Allocator>
    vector<T, Allocator>::iterator vector<T, Allocator>::insert( const_iterator pos, size_type count, const T& value )
    {
        
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
    
}
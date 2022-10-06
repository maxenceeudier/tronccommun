/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_elements.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:21:09 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/06 17:36:18 by maxenceeudi      ###   ########.fr       */
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
}


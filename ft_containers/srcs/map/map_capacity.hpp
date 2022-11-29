/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_capacity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:22 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/28 12:40:17 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "map.hpp"
# include "map.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator >
    bool map<Key, T, Compare, Allocator>::empty() const
    {
        return (this->size() == 0);
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size() const
    {
        size_type  size = 0;
        for (typename map<Key, T, Compare, Allocator>::const_iterator it = this->begin(); it != this->end(); it++)
        {
            size++;
        }
        return (size);
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size() const
    {
        return (_allocNode.max_size());
    }
}
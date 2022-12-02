/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_capacity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:22 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/01 17:20:06 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "set.hpp"
# include "set.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template<class Key, class Compare , class Allocator >
    bool set<Key, Compare, Allocator>::empty() const
    {
        return (this->size() == 0);
    }

    template<class Key, class Compare , class Allocator >
    typename set<Key, Compare, Allocator>::size_type set<Key, Compare, Allocator>::size() const
    {
        size_type  size = 0;
        for (typename set<Key, Compare, Allocator>::const_iterator it = this->begin(); it != this->end(); it++)
        {
            size++;
        }
        return (size);
    }

    template<class Key, class Compare , class Allocator >
    typename set<Key, Compare, Allocator>::size_type set<Key, Compare, Allocator>::max_size() const
    {
        return (_allocNode.max_size());
    }
}
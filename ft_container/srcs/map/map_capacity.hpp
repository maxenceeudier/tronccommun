/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_capacity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:22 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:08:50 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "map.hpp"
# include "map.hpp"
# include <limits>
# include <map>

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
        std::map<Key, T, Compare, Allocator> map_tst;
        size_type mxs = std::numeric_limits<difference_type>::max() / ((sizeof(node_type)) + sizeof(pointer));

        if (map_tst.max_size() == mxs)
            return  (std::numeric_limits<difference_type>::max() / ((sizeof(node_type)) + sizeof(pointer)));
        else
            return  (std::numeric_limits<difference_type>::max() / ((sizeof(node_type))));
    }
}
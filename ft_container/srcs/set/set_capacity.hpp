/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_capacity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:07:22 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:25:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "set.hpp"
# include <set>
# include <limits>

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
        std::set<Key, Compare, Allocator> set_tst;
        size_type mxs = std::numeric_limits<difference_type>::max() / ((sizeof(node_type)) + sizeof(pointer));

        if (set_tst.max_size() == mxs)
            return  (std::numeric_limits<difference_type>::max() / ((sizeof(node_type)) + sizeof(pointer)));
        else
            return  (std::numeric_limits<difference_type>::max() / ((sizeof(node_type))));
    }
}
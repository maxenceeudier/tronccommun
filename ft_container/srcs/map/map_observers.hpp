/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_observers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:19:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::key_compare map<Key, T, Compare, Allocator>::key_comp() const
    {
        return (_comp);
    }

    template<class Key, class T, class Compare , class Allocator >
    typename map<Key, T, Compare, Allocator>::value_compare map<Key, T, Compare, Allocator>::value_comp() const
    {
        return (value_compare(this->_comp));
    }
}
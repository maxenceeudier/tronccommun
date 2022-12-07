/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_observers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:26:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

namespace ft
{
    template<class Key, class Compare , class Allocator >
    typename set<Key, Compare, Allocator>::key_compare set<Key, Compare, Allocator>::key_comp() const
    {
        return (_comp);
    }

    template<class Key, class Compare , class Allocator >
    typename set<Key, Compare, Allocator>::value_compare set<Key, Compare, Allocator>::value_comp() const
    {
        return (value_compare(this->_comp));
    }
}
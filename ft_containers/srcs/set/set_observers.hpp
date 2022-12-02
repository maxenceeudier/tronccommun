/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_observers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/01 17:27:39 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
//#include "../../Include/include.h"

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
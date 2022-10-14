/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:55:04 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/14 18:26:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator >
    std::ostream	&operator<<(std::ostream &o, ft::map<Key, T, Compare, Allocator> &map)
    {
        map._tree.printTree();
        return (o);
    };
}
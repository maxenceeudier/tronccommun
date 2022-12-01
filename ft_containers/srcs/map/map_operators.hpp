/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:55:04 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/29 08:55:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "../../utils/swap.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template<class Key, class T, class Compare , class Allocator >
    std::ostream	&operator<<(std::ostream &o, ft::map<Key, T, Compare, Allocator> &map)
    {
        map._tree.printTree();
        return (o);
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        typename map<Key,T,Compare,Alloc>::const_iterator  it1 = lhs.begin();
        typename map<Key,T,Compare,Alloc>::const_iterator  it2 = rhs.begin();
        while (it1 != lhs.end() && it2!= rhs.end() && it1->first == it2->first && it1->second == it2->second)
        {
            it1++;
            it2++;
        }
        if (it1 == lhs.end() && it2 == rhs.end())
            return (true);
        return (false);
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return (!(lhs == rhs));
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        typename map<Key,T,Compare,Alloc>::const_iterator  it1 = lhs.begin();
        typename map<Key,T,Compare,Alloc>::const_iterator  it2 = rhs.begin();
        while (it1 != lhs.end() && it2!= rhs.end() && it1->first == it2->first && it1->second == it2->second)
        {
            it1++;
            it2++;
        }
        if (it1 == lhs.end() && it2 == rhs.end())
            return (false);
        else if (it2 == rhs.end())
            return (false);
        
        if (it1->first != it2->first)
            return (it1->first < it2->first);
        return (it1->second < it2->second);
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return (!(lhs > rhs));
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return (lhs >= rhs && lhs != rhs);
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        return (!(lhs < rhs));
    };

  
}
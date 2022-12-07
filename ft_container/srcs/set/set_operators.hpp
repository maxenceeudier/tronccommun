/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:55:04 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 12:26:10 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
#include "../../utils/swap.hpp"

namespace ft
{
    template<class Key, class Compare , class Allocator >
    std::ostream	&operator<<(std::ostream &o, ft::set<Key, Compare, Allocator> &set)
    {
        set._tree.printTree();
        return (o);
    };

    template< class Key, class Compare, class Alloc >
    bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        typename set<Key,Compare,Alloc>::const_iterator  it1 = lhs.begin();
        typename set<Key,Compare,Alloc>::const_iterator  it2 = rhs.begin();
        while (it1 != lhs.end() && it2!= rhs.end() && *it1 == *it2)
        {
            it1++;
            it2++;
        }
        if (it1 == lhs.end() && it2 == rhs.end())
            return (true);
        return (false);
    };

    template< class Key, class Compare, class Alloc >
    bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (!(lhs == rhs));
    };

    template< class Key, class Compare, class Alloc >
    bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        typename set<Key,Compare,Alloc>::const_iterator  it1 = lhs.begin();
        typename set<Key,Compare,Alloc>::const_iterator  it2 = rhs.begin();
        while (it1 != lhs.end() && it2!= rhs.end() && *it1 == *it2)
        {
            it1++;
            it2++;
        }
        if (it1 == lhs.end() && it2 == rhs.end())
            return (false);
        else if (it2 == rhs.end())
            return (false);
    
        return (*it1 < *it2);
    };

    template< class Key, class Compare, class Alloc >
    bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (!(lhs > rhs));
    };

    template< class Key, class Compare, class Alloc >
    bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (lhs >= rhs && lhs != rhs);
    };

    template< class Key, class Compare, class Alloc >
    bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
    {
        return (!(lhs < rhs));
    };

  
}
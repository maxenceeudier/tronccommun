/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:55:04 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/13 21:22:39 by meudier          ###   ########.fr       */
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
    
    /*template< class T, class Alloc >
    bool operator==(const ft::map<T,Alloc>& lhs, \
    const ft::map<T,Alloc>& rhs)
    {
        typename ft::map<T, Alloc>::const_iterator itL = lhs.begin();
        typename ft::map<T, Alloc>::const_iterator itR = rhs.begin(); 
        while (itL != lhs.end() && itR != rhs.end() && *itL == *itR)
        {
            itL++;
            itR++;
        }
        if (itL == lhs.end() && itR == rhs.end())
            return (true);
        return (false);
    };


    template< class T, class Alloc >
    bool operator!=( const ft::map<T,Alloc>& lhs, \
    const ft::map<T,Alloc>& rhs )
    {return (!(lhs == rhs));}
    
    template< class T, class Alloc >
    bool operator<( const ft::map<T,Alloc>& lhs, \
    const ft::map<T,Alloc>& rhs )
    {
        typename ft::map<T, Alloc>::const_iterator itL = lhs.begin();
        typename ft::map<T, Alloc>::const_iterator itR = rhs.begin(); 
        while (itL != lhs.end() && itR != rhs.end() && *itR == *itL)
        {
            itL++;
            itR++;
        }
        if (itR != rhs.end())
            return (true);
        return (false);
    };

    template< class T, class Alloc >
    bool operator<=( const ft::map<T,Alloc>& lhs, \
    const ft::map<T,Alloc>& rhs )
    {return (!(lhs > rhs));};

    template< class T, class Alloc >
    bool operator>( const ft::map<T,Alloc>& lhs, \
    const ft::map<T,Alloc>& rhs )
    {return (!(lhs < rhs) && lhs != rhs);};

    template< class T, class Alloc >
    bool operator>=( const ft::map<T,Alloc>& lhs, \
    const ft::map<T,Alloc>& rhs )
    {return (!(lhs < rhs));};*/   
}
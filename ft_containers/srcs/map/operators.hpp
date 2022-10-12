/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:55:04 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 15:55:32 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{
    template< class T, class Alloc >
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

    template< class T, class Alloc>
    std::ostream	&operator<<(std::ostream &o, map<T, Alloc> &vec)
    {
        if (vec.empty())
        {
            std::string empt = "[empty]\n";
            return (o << empt);
        }
            
        typename ft::map<T, Alloc>::iterator  it = vec.begin();

        std::string crochet = "[ ";
        o << crochet;
        while (it != vec.end() - 1)
        {
            o << *it << ", ";
            it++;
        }
        o << *it << " ]\n";
        return (o);
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
    {return (!(lhs < rhs));};         
}
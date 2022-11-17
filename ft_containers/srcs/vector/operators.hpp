/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:28:01 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/17 11:54:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
//#include "../../Include/include.h"

namespace ft
{
    template< class T, class Alloc >
    bool operator==(const ft::vector<T,Alloc>& lhs, \
    const ft::vector<T,Alloc>& rhs)
    {
        typename ft::vector<T, Alloc>::const_iterator itL = lhs.begin();
        typename ft::vector<T, Alloc>::const_iterator itR = rhs.begin(); 
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
    std::ostream	&operator<<(std::ostream &o, vector<T, Alloc> &vec)
    {
        if (vec.empty())
        {
            std::string empt = "[empty]\n";
            return (o << empt);
        }
            
        typename ft::vector<T, Alloc>::iterator  it = vec.begin();

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
    bool operator!=( const ft::vector<T,Alloc>& lhs, \
    const ft::vector<T,Alloc>& rhs )
    {return (!(lhs == rhs));}
    
    template< class T, class Alloc >
    bool operator<( const ft::vector<T,Alloc>& lhs, \
    const ft::vector<T,Alloc>& rhs )
    {
        typename ft::vector<T, Alloc>::const_iterator itL = lhs.begin();
        typename ft::vector<T, Alloc>::const_iterator itR = rhs.begin(); 
        while (itL != lhs.end() && itR != rhs.end() && *itR == *itL)
        {
            itL++;
            itR++;
        }
        if (itL == lhs.end() && itR == rhs.end())
            return (false);
        else if (itR == rhs.end())
            return (false);
        return (*itL < *itR);
    };

    template< class T, class Alloc >
    bool operator<=( const ft::vector<T,Alloc>& lhs, \
    const ft::vector<T,Alloc>& rhs )
    {return (!(lhs > rhs));};

    template< class T, class Alloc >
    bool operator>( const ft::vector<T,Alloc>& lhs, \
    const ft::vector<T,Alloc>& rhs )
    {return (!(lhs < rhs) && lhs != rhs);};

    template< class T, class Alloc >
    bool operator>=( const ft::vector<T,Alloc>& lhs, \
    const ft::vector<T,Alloc>& rhs )
    {return (!(lhs < rhs));};         
}
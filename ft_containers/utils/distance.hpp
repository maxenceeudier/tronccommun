/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:41 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/06 15:31:59 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP
#include "../srcs/vector/vector_iterator.hpp"

namespace ft
{
    
    template<class InputIterator>
    typename ft::vectorIterator<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last)
    {
        typename ft::vectorIterator<InputIterator>::difference_type rtn = 0;
        while (first != last)
        {
            first++;
            rtn++;
        }
        return (rtn);
    };

}

#endif
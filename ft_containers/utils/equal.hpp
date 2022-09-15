/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:21:41 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/09/15 14:57:35 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
    template <class Iterator1, class Iterator2>
    bool equal (Iterator1 first1, Iterator1 last1, Iterator2 first2 )
    {
    while (first1 != last1) {
        if (!(*first1 == *first2))
            return false;
        ++first1; ++first2;
    }
    return true;
    }
}

#endif
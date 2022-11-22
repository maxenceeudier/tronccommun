/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:14:52 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/21 07:46:59 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONAL_HPP
#define CONDITIONAL_HPP

namespace ft
{
    template <bool B, typename T1, typename T2>
    struct conditional
    {
        typedef  T2 type;
    };

    template <typename T1, typename T2>
    struct conditional<true, T1, T2>
    {
        typedef  T1 type;
    };
    
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:37:19 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 09:53:23 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template<typename T>
void    swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
const T &min(const T &a, const T &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

template<typename T>
const T &max(const T &a, const T &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

#endif
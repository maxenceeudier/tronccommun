/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:55:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 10:38:35 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T, typename U>
void    iter(T *array, int size, U (*f)(T &data))
{
    int i = 0;
    while (i < size)
        (*f)(array[i++]);
}

template<typename T>
void    print(T &data)
{
    std::cout << data << " ";
    return ;
}

template<typename T>
int     increment(T &data)
{
    data++;
    return (0);
}

#endif
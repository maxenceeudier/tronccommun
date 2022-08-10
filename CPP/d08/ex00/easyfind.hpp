/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:42:34 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 17:35:38 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator rslt = find(container.begin(), container.end(), n);
    if (rslt == container.end())
        return (container.end());
    return (rslt);
}

#endif
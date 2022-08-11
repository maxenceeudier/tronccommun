/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:58:11 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/11 10:32:07 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v(10);
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    std::cout << *(::easyfind(v, 1)) << std::endl;
    std::cout << *::easyfind(v, 11) << std::endl;
    std::cout << *::easyfind(v, -3) << std::endl;
    std::cout << *::easyfind(v, 9) << std::endl;
    return (0);
}
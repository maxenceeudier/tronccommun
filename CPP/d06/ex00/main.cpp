/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:10:49 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 10:49:21 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertType.hpp"
#include <iostream>

int main(int ac, char **av)
{
    ConvertType convert;
    if (ac != 2)
    {
        std::cout << "Bad format: please put one argument." << std::endl;
        return (0);
    }
    return (convert.printData(std::string(av[1])));
}
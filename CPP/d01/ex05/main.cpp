/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:41:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/28 10:53:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Harl    harl;

    if (ac == 2)
        harl.complain(av[1]);
    else
    {
        std::cout << "You must indicate one level:" << std::endl;
        std::cout << "(DEBUG / INFO / WARNING / ERROR)" << std::endl;
    }
    
    return (0);
}
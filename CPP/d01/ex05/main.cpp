/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:41:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 16:32:21 by meudier          ###   ########.fr       */
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
        std::cout << "Wrong nb of args" << std::endl;
    
    return (0);
}
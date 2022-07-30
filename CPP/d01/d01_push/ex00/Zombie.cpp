/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:55 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 09:02:34 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << this->_name;
    std::cout << " is born." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name;
    std::cout << " is dead." << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->_name;
    std::cout << " : BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
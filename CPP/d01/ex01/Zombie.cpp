/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:55 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/28 10:08:51 by meudier          ###   ########.fr       */
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

Zombie::Zombie()
{
    std::cout << "A new Zombie is born." << std::endl;
    return ;
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

void    Zombie::setname(std::string name)
{
    this->_name = name;
    return ;
}
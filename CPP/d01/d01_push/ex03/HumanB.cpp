/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:45:44 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 15:54:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void    HumanB::attack()
{
    std::cout << this->_name << " attacks with ";
    if (this->_weapon)
        std::cout << "their " << this->_weapon->getType() << std::endl;
    else
        std::cout << "their arms" << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return ;
}

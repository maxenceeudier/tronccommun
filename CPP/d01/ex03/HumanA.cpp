/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:33:23 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 12:58:50 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}


void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their ";
    std::cout << this->_weapon.getType() << std::endl;
    return ;
}

void    HumanA::setWeapon(Weapon &weapon)
{
    this->_weapon = weapon;
    return ;
}

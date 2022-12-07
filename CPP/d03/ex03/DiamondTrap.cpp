/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:36:09 by meudier           #+#    #+#             */
/*   Updated: 2022/08/02 16:59:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {}

DiamondTrap::DiamondTrap(std::string name) //: FragTrap(name), ScavTrap(name)
{
    ClapTrap::_name = name + "_clap_name";
    ClapTrap::_hit = FragTrap::getHit();
    ClapTrap::_damage = FragTrap::getDamage();
    ClapTrap::_nrj = ScavTrap::_nrj;
    this->_name = name;
    this->_hit = FragTrap::_hit;
    this->_nrj = ScavTrap::_nrj;
    this->_damage = FragTrap::_damage;
    std::cout << "Diamond constructor with name called. ";
    std::cout << this->_name << " is born."  << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) : ClapTrap(), FragTrap(), ScavTrap()
{
    *this = cpy;
    std::cout << "DiamondTrap cpy constructor called. ";
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap: " << this->_name << " is dead.";
    std::cout << std::endl;
    return ;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &diamond2)
{
    std::cout << "Diamond Assignement operator called" << std::endl;
    this->_hit = diamond2._hit;
    this->_nrj = diamond2._nrj;
    this->_name = diamond2._name;
    this->_damage = diamond2._damage;
    return (*this);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "Who am i ?? I am ";
    std::cout << this->_name << " !! the descendant of  " << ClapTrap::_name;
    std::cout << " !!!" << std::endl <<  std::endl;
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
    return ;
}
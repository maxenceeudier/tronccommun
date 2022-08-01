/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:45:45 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/01 18:17:10 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _guardGateStatus(0)
{
    std::cout << "ScavTrap default constructor called. " << std::endl;
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name) : _guardGateStatus(0)
{
    this->_name = name;
    this->_hit = 100;
    this->_nrj = 50;
    this->_damage = 20;
    std::cout << "ScavTrap constructor whith name called. ";
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &cpy)
{
    *this = cpy;
    std::cout << "ScavTrap cpy constructor called. ";
    std::cout << this->_name << " is born."  << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap: " << this->_name << " is dead.";
    std::cout << std::endl;
    return ;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &scav2)
{
    std::cout << "ScavTrap Assignement operator called" << std::endl;
    this->_hit = scav2._hit;
    this->_nrj = scav2._nrj;
    this->_name = scav2._name;
    this->_damage = scav2._damage;
    this->_guardGateStatus = scav2._guardGateStatus;
    return (*this);
}

void    ScavTrap::guardGate(void)
{
    
    if (this->_guardGateStatus)
    {
        std::cout << this->_name << "End of Gate Keeper mode !";
        this->_damage /= 2;
        this->_guardGateStatus = 0;
    }
    else
    {
        std::cout << this->_name << " is in Gate Keeper mode !";
        this->_damage *= 2;
        this->_guardGateStatus = 1;
    }
    std::cout << std::endl << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->_nrj)
    {
        this->_nrj--;
        std::cout << "ScavTrap: ";
        std::cout << this->_name;
        std::cout << " attack " << target;
        std::cout << " causing " << this->_damage;
        std::cout << " points of damage." << std::endl;
        if (this->_guardGateStatus)
        {
            this->_nrj /= 2;
        }
        if (this->_nrj == 0)
        {
            std::cout << this->_name;
            std::cout << " can't moove anymore, he has no more energie...";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Be carreful he has only " << this->_nrj;
            std::cout << " energie points left." << std::endl;
        }
    }
    else
    {
        std::cout << "ScavTrap: ";
        std::cout << this->_name << " hasn't the energie to attack.";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return ;
}
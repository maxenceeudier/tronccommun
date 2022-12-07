/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:58:38 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 16:55:14 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("A claptrap"), _hit(10), _nrj(10), _damage(0)
{
    std::cout << "ClapTrap default constructor called. ";
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _nrj(10), _damage(0)
{
    std::cout << "ClapTrap constructor with name called. ";
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap &cpy)
{
    std::cout << "ClapTrap cpy constructor called. ";
    std::cout << this->_name << " is born."  << std::endl;
    *this = cpy;
    return ;
}

ClapTrap::~ClapTrap(void)
{
        std::cout << "claptrap: " << this->_name << " is dead." << std::endl;
    return ;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &clap2)
{
    std::cout << "ClapTrap Assignement operator called" << std::endl;
    this->_hit = clap2._hit;
    this->_nrj = clap2._nrj;
    this->_name = clap2._name;
    this->_damage = clap2._damage;
    return (*this);
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_nrj)
    {
        std::cout << "ClapTrap: ";
        this->_nrj--;
        std::cout << this->_name;
        std::cout << " attack " << target;
        std::cout << " causing " << this->_damage;
        std::cout << " points of damage." << std::endl;
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
        std::cout << "ClapTrap: ";
        std::cout << this->_name << " hasn't the energie to attack.";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit > amount)
    {
        this->_hit -= amount;
        std::cout << "Outch ! " << this->_name;
        std::cout << " loose " << amount;
        std::cout << " hit points ! ";  
        std::cout << "Only got " << this->_hit;
        std::cout << " hit points left !" << std::endl;
    }
    else
    {
        
        std::cout << "Oh wow ! " << this->_name;
        std::cout << " took a critical attack..." << " he loose his ";
        std::cout << this->_hit << " last hit points.";
        std::cout << " He will not rise up ..." << std::endl;
        this->_hit = 0;
        this->_nrj = 0;
    }
    std::cout << std::endl;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_nrj)
    {
        this->_hit += amount;
        this->_nrj--;
        std::cout << "Ouf !! " << this->_name;
        std::cout << " take back " << (int)amount;
        std::cout << " hit points";
        std::cout << " he has now " << this->_hit;
        std::cout << " hit points !" << std::endl;
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
        std::cout << this->_name << " has not the energie to be repaired.";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return ; 
}

unsigned int &ClapTrap::getDamage(void)
{
    return (this->_damage);
}

std::string     &ClapTrap::getName(void)
{
    return (this->_name);
}

unsigned int    &ClapTrap::getNrj(void)
{
    return (_nrj);
}
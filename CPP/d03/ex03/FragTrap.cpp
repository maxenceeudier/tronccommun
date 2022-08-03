/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:45:45 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 16:58:05 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_hit = 100;
    hit = 100;
    this->_nrj = 100;
    this->_damage = 30;
    std::cout << "FragTrap default constructor called. " << std::endl;
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    this->_hit = 100;
    hit = 100;
    this->_nrj = 100;
    this->_damage = 30;
    std::cout << "FragTrap constructor whith name called. ";
    std::cout << this->_name << " is born."  << std::endl;
    return ;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap()
{
    *this = cpy;
    std::cout << "FragTrap cpy constructor called. ";
    std::cout << this->_name << " is born."  << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap: " << this->_name << " is dead.";
    std::cout << std::endl;
    return ;
}

FragTrap    &FragTrap::operator=(FragTrap const &Frag2)
{
    std::cout << "FragTrap Assignement operator called" << std::endl;
    this->_hit = Frag2._hit;
    this->_nrj = Frag2._nrj;
    this->_name = Frag2._name;
    this->_damage = Frag2._damage;
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    if (_hit > 5)
    {
        _hit -= 5;
        _nrj += 10;
        std::cout << _name << " did a High Five !! Yeah !! He has now ";
        std::cout << _hit << " hit points and " << _nrj << " energie points.";
        std::cout << std::endl;
    }
    else
    {
        std::cout << _name << " hasn't enought hit points to do a high five ...";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

unsigned int    FragTrap::getDamage(void) const
{
    return (_damage);
}

unsigned int    FragTrap::getHit(void) const
{
    return (hit);
}
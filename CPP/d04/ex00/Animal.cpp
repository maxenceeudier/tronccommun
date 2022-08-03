/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:46:54 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:08:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

Animal::Animal(const Animal &cpy)
{
    std::cout << "Animal cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal detructor called" << std::endl;
    return ;
}

Animal  &Animal::operator=(Animal const &animal2)
{
    std::cout << "Animal assignement operator called" << std::endl;
    this->_type = animal2.getType();
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "ssssbbbbBBBRRRRAAAAA !!!!" << std::endl;
    return ;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}
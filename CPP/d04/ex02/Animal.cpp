/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:46:54 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:52:35 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

Animal::Animal(void) : _type("Animal")
{
    if (PRINT)
        std::cout << "Animal default constructor called" << std::endl;
    return ;
}

Animal::Animal(const Animal &cpy)
{
    if (PRINT)
        std::cout << "Animal cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Animal::~Animal(void)
{
    if (PRINT)
        std::cout << "Animal detructor called" << std::endl;
    return ;
}

Animal  &Animal::operator=(Animal const &animal2)
{
    if (PRINT)
        std::cout << "Animal assignement operator called" << std::endl;
    this->_type = animal2.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

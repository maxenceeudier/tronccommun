/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:46:54 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:08:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
    std::cout << "WrongAnimal cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal detructor called" << std::endl;
    return ;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &Wronganimal2)
{
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    this->_type = Wronganimal2.getType();
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "YOOOOOOOOOOO !!!!" << std::endl;
    return ;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}
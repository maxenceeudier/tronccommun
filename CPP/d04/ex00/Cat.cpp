/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:40:15 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:06:48 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
    return ;
}
Cat::Cat(const Cat &cpy) : Animal()
{
    std::cout << "Cat cpy constructor called" << std::endl;
    *this = cpy;    return ;
}

Cat::~Cat(void)
{
    std::cout << "Cat detructor called" << std::endl;
    return ;
}

Cat  &Cat::operator=(const Cat &Cat2)
{
    std::cout << "Cat assignement operator called" << std::endl;
    _type = Cat2._type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "miaou." << std::endl;
    return ;
}
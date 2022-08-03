/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:39:24 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:07:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog &cpy) : Animal()
{
    std::cout << "Dog cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Dog::~Dog(void)
{
    std::cout << "Dog detructor called" << std::endl;
    return ;
}

Dog  &Dog::operator=(const Dog &Dog2)
{
    std::cout << "Dog assignement operator called" << std::endl;
    _type = Dog2._type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "WOhAFF !!!" << std::endl;
    return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:39:24 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 16:52:36 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

Dog::Dog(void)
{
    if (PRINT)
        std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
    _brain->addIdeas("jouer !");
    _brain->addIdeas("jouer !");
    _brain->addIdeas("manger !");
    _brain->addIdeas("jouer !");
    _brain->addIdeas("dormir !");
    return ;
}

Dog::Dog(const Dog &cpy) : Animal()
{
    if (PRINT)
        std::cout << "Dog cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Dog::~Dog(void)
{
    if (PRINT)
        std::cout << "Dog detructor called" << std::endl;
    delete _brain;
    return ;
}

Dog  &Dog::operator=(const Dog &Dog2)
{
    if (PRINT)
        std::cout << "Dog assignement operator called" << std::endl;
    this->_type = Dog2._type;
    _brain = new Brain();
    *(_brain) = *(Dog2._brain);
    return (*this);
}

Animal  &Dog::operator=(Animal const &animal2)
{
    if (PRINT)
        std::cout << "Animal assignement operator called" << std::endl;
    this->_type = animal2.getType();
    *_brain = *(animal2.getBrain());
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "WOhAFF !!!" << std::endl;
    return ;
}

Brain   *Dog::getBrain(void) const
{
    return (this->_brain);
}
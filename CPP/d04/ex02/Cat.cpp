/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:40:15 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 17:01:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

Cat::Cat(void)
{
    if (PRINT)
        std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
    _brain->addIdeas("dormmir");
    _brain->addIdeas("mepriser les humains");
    _brain->addIdeas("manger");
    return ;
}
Cat::Cat(const Cat &cpy) : Animal()
{
    if (PRINT)
        std::cout << "Cat cpy constructor called" << std::endl;
    *this = cpy;    return ;
}

Cat::~Cat(void)
{
    if (PRINT)
        std::cout << "Cat detructor called" << std::endl;
    delete _brain;
    return ;
}

Cat  &Cat::operator=(const Cat &Cat2)
{
    if (PRINT)
        std::cout << "Cat assignement operator called" << std::endl;
    _type = Cat2._type;
    _brain = new Brain();
    *(_brain) = *(Cat2._brain);
    return (*this);
}

Animal  &Cat::operator=(Animal const &animal2)
{
    if (PRINT)
        std::cout << "Animal assignement operator called" << std::endl;
    this->_type = animal2.getType();
    *(_brain) = *(animal2.getBrain());
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "miaou." << std::endl;
    return ;
}

Brain   *Cat::getBrain(void) const
{
    return (this->_brain);
}
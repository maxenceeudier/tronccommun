/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:40:15 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:06:48 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    _type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
    return ;
}
WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal()
{
    std::cout << "WrongCat cpy constructor called" << std::endl;
    *this = cpy;    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat detructor called" << std::endl;
    return ;
}

WrongCat  &WrongCat::operator=(const WrongCat &WrongCat2)
{
    std::cout << "WrongCat assignement operator called" << std::endl;
    _type = WrongCat2._type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Sound of " << _type << " is ";
    std::cout << "MIIIIAAAOOOOOUUUU." << std::endl;
    return ;
}
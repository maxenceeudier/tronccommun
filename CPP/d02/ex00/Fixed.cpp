/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:50:16 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 08:46:19 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bitsPartFract = 8;

Fixed::Fixed() : _nbVirguleFixe(0)
{
    std::cout << "Default constructeur called" << std::endl;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Detructeur called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &cpy)
{
    std::cout << "Copy constructeur called" << std::endl;
    *this = cpy;
    return ;
}

Fixed   &Fixed::operator=(Fixed const &fixed2)
{
    std::cout << "Copy assignement operateur called" << std::endl;
    this->_nbVirguleFixe = fixed2.getRawBits();
    return (*this);
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nbVirguleFixe);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_nbVirguleFixe = raw;
    return ;
}
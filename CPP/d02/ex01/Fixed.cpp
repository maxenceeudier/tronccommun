/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:50:16 by meudier           #+#    #+#             */
/*   Updated: 2022/07/30 17:03:33 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int _nbBits = 0;

Fixed::Fixed() : _nb(0)
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
    this->_nb = fixed2.getRawBits();
    return (*this);
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nb);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_nb = raw;
    return ;
}

Fixed::Fixed(const int i)
{
    this->_nb = i << this->_fractBits;
    return ;
}
        
Fixed::Fixed(const float f)
{
    int i;

    i = 1 << this->_fractBits;
    this->_nb = (int)roundf(f * i);
    return ;
}
float Fixed::toFloat(void) const
{
    int     i;
    float   ret;    

    i = 1 << this->_fractBits;
    ret = (float)this->_nb / i;
    return (ret);
}
        
int Fixed::toInt(void) const
{
    return (this->_nb >> _fractBits);
}

std::ostream    &operator<<(std::ostream &o, Fixed const & instance)
{
    o << instance.toFloat();
    return (o);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:50:16 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 08:55:20 by maxenceeudi      ###   ########.fr       */
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
    this->_nbVirguleFixe = fixed2._nbVirguleFixe;
    return (*this);
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_nbVirguleFixe);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_nbVirguleFixe = raw;
    return ;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructeur called" << std::endl;
    this->_nbVirguleFixe = i << _bitsPartFract;
    return ;
}
        
Fixed::Fixed(const float f)
{
    int i;

    std::cout << "Float constructeur called" << std::endl;
    i = 1 << _bitsPartFract;
    this->_nbVirguleFixe = (int)roundf(f * i);
    return ;
}
float Fixed::toFloat(void) const
{
    int     i;
    float   ret;    

    i = 1 << _bitsPartFract;
    ret = (float)this->_nbVirguleFixe / i;
    return (ret);
}
        
int Fixed::toInt(void) const
{
    return (this->_nbVirguleFixe >> _bitsPartFract);
}

std::ostream    &operator<<(std::ostream &o, Fixed const & instance)
{
    o << instance.toFloat();
    return (o);
}
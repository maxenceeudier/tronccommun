/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:50:16 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 11:04:46 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bitsPartFract = 8;

Fixed::Fixed() : _nbVirguleFixe(0)
{
    if (PRINT)
        std::cout << "Default constructeur called" << std::endl;
    return ;
}

Fixed::~Fixed()
{
    if (PRINT)
        std::cout << "Detructeur called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &cpy)
{
    if (PRINT)
        std::cout << "Copy constructeur called" << std::endl;
    *this = cpy;
    return ;
}

Fixed   &Fixed::operator=(Fixed const &fixed2)
{
    if (PRINT)
        std::cout << "Copy assignement operateur called" << std::endl;
    this->_nbVirguleFixe = fixed2.getRawBits();
    return (*this);
}

int    Fixed::getRawBits(void) const
{
    if (PRINT)
        std::cout << "getRawBits member function called" << std::endl;
    return (this->_nbVirguleFixe);
}

void    Fixed::setRawBits(int const raw)
{
    if (PRINT)
        std::cout << "setRawBits member function called" << std::endl;
    this->_nbVirguleFixe = raw;
    return ;
}

Fixed::Fixed(const int i)
{
    if (PRINT)
        std::cout << "Int constructeur called" << std::endl;
    this->_nbVirguleFixe = i << Fixed::_bitsPartFract;
    return ;
}
        
Fixed::Fixed(const float f)
{
    int i;

    if (PRINT)
        std::cout << "Float constructeur called" << std::endl;
    i = 1 << Fixed::_bitsPartFract;
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
    return (this->_nbVirguleFixe >> Fixed::_bitsPartFract);
}

std::ostream    &operator<<(std::ostream &o, const Fixed & instance)
{
    o << instance.toFloat();
    return (o);
}

bool    Fixed::operator<(const Fixed &fixed2) const
{
    return (this->getRawBits() < fixed2.getRawBits());
}

bool    Fixed::operator<=(const Fixed &fixed2) const
{
    return (this->getRawBits() <= fixed2.getRawBits());
}

bool    Fixed::operator>=(const Fixed &fixed2) const
{
    return (this->getRawBits() >= fixed2.getRawBits());
}

bool    Fixed::operator>(const Fixed &fixed2) const
{
    return (this->getRawBits() > fixed2.getRawBits());
}

bool    Fixed::operator==(const Fixed &fixed2) const
{
    return (this->getRawBits() == fixed2.getRawBits());
}

bool    Fixed::operator!=(const Fixed &fixed2) const
{
    return (this->getRawBits() != fixed2.getRawBits());
}

Fixed   Fixed::operator+(const Fixed &fixed2) const
{
    Fixed   result;
    result._nbVirguleFixe = this->getRawBits() + fixed2.getRawBits();
    return (result);
}

Fixed   Fixed::operator-(const Fixed &fixed2) const
{
    Fixed   result;
    result._nbVirguleFixe = this->getRawBits() - fixed2.getRawBits();
    return (result);
}

Fixed   Fixed::operator*(const Fixed &fixed2) const
{
    Fixed   result(this->toFloat() * fixed2.toFloat());
    return (result); 
}

Fixed   Fixed::operator/(const Fixed &fixed2) const
{
    Fixed   result(this->toFloat() / fixed2.toFloat());
    return (result); 
}

Fixed   &Fixed::operator++(void)
{
    this->_nbVirguleFixe++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);
    ++(*this);
    return (temp);
}

Fixed   &Fixed::operator--(void)
{
    this->_nbVirguleFixe--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);
    --(*this);
    return (temp);
}

Fixed        &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    else
        return (fixed2);    
}

const Fixed  &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return (fixed1);
    else
        return (fixed2);
}

Fixed        &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 > fixed2)
        return (fixed1);
    else
        return (fixed2); 
}

const Fixed  &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 > fixed2)
        return (fixed1);
    else
        return (fixed2); 
}
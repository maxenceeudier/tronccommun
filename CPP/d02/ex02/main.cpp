/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:48:34 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 11:03:45 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	make_tests(int value_of_b, float value_of_c)
{
	std::cout << "Initialisations" << std::endl;
    
    std::cout << "default constructor" << std::endl;
    Fixed a;
	std::cout << "Value of a is: " << a << std::endl;
    
    std::cout << "int constructor" << std::endl;
	const Fixed b(value_of_b);
	std::cout << "Value of b is: " << b << std::endl;

    std::cout << "float constructor" << std::endl;
	const Fixed c(value_of_c);
	std::cout << "Value of c is: " << c << std::endl;

    std::cout << "cpy constructor" << std::endl;
	Fixed d(c);
	std::cout << "Value of d is: " << d << std::endl;

	std::cout << "Assignation operator (a = b)" << std::endl;
	a = b;
	std::cout << "Value of a is: " << a << std::endl << std::endl;

	std::cout << "Comparison operators" << std::endl;
	std::cout << "a < c is " << (a < c) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > c is " << (a > c) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a == c is " << (a == c) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != c is " << (a != c) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl << std::endl;

	std::cout << "Arithmetic operator" << std::endl;
	std::cout << "c + a = " << c + a << std::endl;
	std::cout << "c - a = " << c - a << std::endl;
	std::cout << "c * a = " << c * a << std::endl;
	std::cout << "c / a = " << c / a << std::endl << std::endl;

	std::cout << "Incrementation and decrementation operators" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "Value of a is: " << a << std::endl << std::endl;

	std::cout << "Convertion" << std::endl;
	std::cout << "c.toInt() = " << c.toInt() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl << std::endl;;

    std::cout << "min and max" << std::endl;
	std::cout << "min(a, d) = " << Fixed::min(a, d) << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(a, d) = " << Fixed::max(a, d) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl << std::endl;
}
int main( void )
{
    Fixed a;
    Fixed const b(Fixed(5.05f)*Fixed(2));
 
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a,b) <<std::endl << std::endl;
    
	make_tests(14, 50.125f);
	std::cout << "Now same thing but with negative numbers:" << std::endl << std::endl;
	make_tests(-12, -80.175829380f);
}

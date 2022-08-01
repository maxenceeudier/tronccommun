/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:49:33 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 11:06:10 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# define PRINT 0

#include <iostream>
#include <cmath>

class   Fixed
{
    private:
        int                 _nbVirguleFixe;
        static const int    _bitsPartFract;
    public:
        Fixed(void);
        Fixed(Fixed const &cpy);
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed(void);
        Fixed   &operator=(const Fixed &fixed2);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        bool    operator<(const Fixed &fixed2) const;
        bool    operator<=(const Fixed &fixed2) const;
        bool    operator>=(const Fixed &fixed2) const;
        bool    operator>(const Fixed &fixed2) const;
        bool    operator==(const Fixed &fixed2) const;
        bool    operator!=(const Fixed &fixed2) const;

        Fixed   operator+(const Fixed &fixed2) const;
        Fixed   operator-(const Fixed &fixed2) const;
        Fixed   operator*(const Fixed &fixed2) const;
        Fixed   operator/(const Fixed &fixed2) const;

        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);

        static Fixed        &min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed  &min(const Fixed &fixed1, const Fixed &fixed2);
        static Fixed        &max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed  &max(const Fixed &fixed1, const Fixed &fixed2);
        
};

std::ostream    &operator<<(std::ostream &o, Fixed const & instance);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:49:33 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 08:49:03 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
        Fixed   &operator=(Fixed const &fixed2);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const & instance);

#endif
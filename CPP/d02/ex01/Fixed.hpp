/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:49:33 by meudier           #+#    #+#             */
/*   Updated: 2022/07/30 17:04:10 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    private:
        int                 _nb;
        static const int    _fractBits = 8;
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
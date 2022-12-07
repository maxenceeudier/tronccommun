/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:49:33 by meudier           #+#    #+#             */
/*   Updated: 2022/08/01 08:29:55 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class   Fixed
{
    private:
        int                 _nbVirguleFixe;
        static const int    _bitsPartFract;
    public:
        Fixed(void);
        Fixed(const Fixed &cpy);
        ~Fixed(void);
        Fixed   &operator=(const Fixed &fixed2);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif
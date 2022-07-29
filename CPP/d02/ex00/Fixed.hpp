/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:49:33 by meudier           #+#    #+#             */
/*   Updated: 2022/07/29 14:04:41 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class   Fixed
{
    private:
        int                 _nb;
        static const int    _nbBits;
    public:
        Fixed(void);
        Fixed(Fixed const &cpy);
        ~Fixed(void);
        Fixed   &operator=(Fixed const &fixed2);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif
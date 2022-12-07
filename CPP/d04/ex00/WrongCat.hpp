/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:39:45 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:07:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCAT_HPP
#define WrongCAT_HPP
#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(const WrongCat &cpy);
        ~WrongCat(void);
        WrongCat  &operator=(const WrongCat &WrongCat2);

        void    makeSound(void) const;
};

#endif
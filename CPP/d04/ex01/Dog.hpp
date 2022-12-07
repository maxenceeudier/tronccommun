/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:38:37 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:16:46 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "includes.h"

class   Dog : public Animal
{
    private:
        Brain   *_brain;
    public:
        Dog(void);
        Dog(const Dog &cpy);
        virtual ~Dog(void);
        virtual Dog  &operator=(const Dog &Dog2);
        virtual Animal &operator=(const Animal &animal2);

        virtual void   makeSound(void) const;
        virtual Brain   *getBrain(void) const;
};

#endif
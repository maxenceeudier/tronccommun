/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:40:42 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:52:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "includes.h"

class   Animal
{
    protected:
    std::string _type;
    public:
        Animal(void);
        Animal(const Animal &cpy);
        virtual ~Animal(void);
        virtual Animal  &operator=(Animal const &animal2);

        std::string     getType(void) const;
        virtual Brain   *getBrain(void) const = 0;
        void virtual    makeSound(void) const = 0;
};

#endif
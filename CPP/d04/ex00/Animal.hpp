/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:40:42 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:34:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class   Animal
{
    protected:
    std::string _type;
    public:
        Animal(void);
        Animal(const Animal &cpy);
        virtual ~Animal(void);
        Animal  &operator=(Animal const &animal2);
        
        virtual void    makeSound(void) const;
        std::string     getType(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:38:37 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:07:12 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class   Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog &cpy);
        ~Dog(void);
        Dog  &operator=(const Dog &Dog2);

        void virtual    makeSound(void) const;
};

#endif
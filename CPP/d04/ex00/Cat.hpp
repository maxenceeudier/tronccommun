/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:39:45 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:07:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class   Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat &cpy);
        ~Cat(void);
        Cat  &operator=(const Cat &Cat2);

        void virtual    makeSound(void) const;
};

#endif
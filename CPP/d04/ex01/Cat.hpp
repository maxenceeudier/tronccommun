/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:39:45 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:46:27 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "includes.h"

class   Cat : public Animal
{
    private:
        Brain   *_brain;
    public:
        Cat(void);
        Cat(const Cat &cpy);
        virtual ~Cat(void);
        virtual Cat  &operator=(const Cat &Cat2);
        virtual Animal  &operator=(const Animal &Cat2);

        virtual void    makeSound(void) const;
        virtual Brain   *getBrain(void) const;
};

#endif
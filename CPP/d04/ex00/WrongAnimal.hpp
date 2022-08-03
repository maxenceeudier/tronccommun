/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:40:42 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 11:08:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP
#include <iostream>

class   WrongAnimal
{
    protected:
    std::string _type;
    public:
        WrongAnimal(void) ;
        WrongAnimal(const WrongAnimal &cpy);
        virtual ~WrongAnimal(void);
        WrongAnimal  &operator=(WrongAnimal const &Wronganimal2);
        
        void            makeSound(void) const;
        std::string     getType(void) const;
};

#endif
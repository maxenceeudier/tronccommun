/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:23:10 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/30 17:09:51 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::Weapon() {}

Weapon::~Weapon() {}

const std::string  &Weapon::getType(void)
{
    return (this->_type);
}
    
void    Weapon::setType(std::string type)
{
    this->_type = type;
    return ;
}
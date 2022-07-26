/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:33:26 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 12:58:36 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon      &_weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    
    void    attack(void);
    void    setWeapon(Weapon &weapon);
};



#endif
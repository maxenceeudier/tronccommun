/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:59:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/01 18:17:39 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::string aName = "Sasuke";
    std::string bName = "Naruto";
    
    ScavTrap    a(aName);
    ScavTrap    b(bName);
    ClapTrap    d("claptrap");
    ScavTrap    c = ScavTrap("Sakura");

    a.attack(b.getName());
    b.takeDamage(a.getDamage());
    
    b.attack(c.getName());
    c.takeDamage(b.getDamage());

    d.attack(a.getName());
    a.takeDamage(d.getDamage());

    b.attack(d.getName());
    d.takeDamage(b.getDamage());

    c.guardGate();
    c.attack(a.getName());
    a.takeDamage(c.getDamage());
    c.guardGate();
    c.attack(a.getName());
    a.takeDamage(c.getDamage());
    

    return (0);
}
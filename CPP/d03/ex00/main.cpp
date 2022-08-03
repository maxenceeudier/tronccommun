/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:59:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 09:25:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    a("Sasuke");
    ClapTrap    b("Naruto");
    ClapTrap    c(a);
    ClapTrap    d = b;

    a.attack(b.getName());
    b.takeDamage(a.getDamage());
    
    b.beRepaired(2);
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    
    a.beRepaired(4);
    a.attack(b.getName());
    b.takeDamage(a.getDamage());
    
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    b.beRepaired(1);
    b.beRepaired(3);
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    b.attack(a.getName());
    a.takeDamage(b.getDamage());
    b.attack(a.getName());

    c.attack(d.getName());
    d.takeDamage(c.getDamage());
    
    return (0);
}
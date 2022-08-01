/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:59:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/01 16:52:48 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::string s = "Sasuke";
    std::string n = "Naruto";
    ClapTrap    a(s);
    ClapTrap    b(n);
    ClapTrap    c(a);
    ClapTrap    d = b;

    a.attack(n);
    b.takeDamage(a.getDamage());
    b.beRepaired(2);
    b.attack(s);
    a.takeDamage(b.getDamage());
    b.attack(s);
    a.takeDamage(b.getDamage());
    a.beRepaired(4);
    a.attack(n);
    b.takeDamage(a.getDamage());
    b.attack(s);
    a.takeDamage(b.getDamage());
    b.attack(s);
    a.takeDamage(b.getDamage());
    b.attack(s);
    a.takeDamage(b.getDamage());
    b.beRepaired(-1);
    b.beRepaired(3);
    b.attack(s);
    a.takeDamage(b.getDamage());
    b.attack(s);
    a.takeDamage(b.getDamage());
    b.attack(s);
    a.takeDamage(b.getDamage());

    c.attack(n);
    d.takeDamage(c.getDamage());
    
    return (0);
}
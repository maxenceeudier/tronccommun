/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:59:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 10:04:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{ 
    FragTrap    a("Sasuke");
    FragTrap    b("Naruto");
    ClapTrap    d("claptrap");
    FragTrap    c = FragTrap("Sakura");

    a.attack(b.getName());
    b.takeDamage(a.getDamage());
    
    b.attack(c.getName());
    c.takeDamage(b.getDamage());

    d.attack(a.getName());
    a.takeDamage(d.getDamage());

    b.attack(d.getName());
    d.takeDamage(b.getDamage());

    c.highFivesGuys();
    c.attack(a.getName());
    a.takeDamage(c.getDamage());
    c.highFivesGuys();
    c.attack(a.getName());
    a.takeDamage(c.getDamage());
    

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:48:51 by meudier           #+#    #+#             */
/*   Updated: 2022/08/02 16:57:29 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("Jiraya");

    a.attack("Pain");
    a.whoAmI();
    a.takeDamage(5);
    a.guardGate();
    a.attack("Pain");
    a.guardGate();
    a.highFivesGuys();
    a.beRepaired(10);
    a.whoAmI();
    a.highFivesGuys();
    a.takeDamage(10);
    a.takeDamage(30);
    a.guardGate();
    a.attack("Pain");
    a.highFivesGuys();
    a.guardGate();
    
}
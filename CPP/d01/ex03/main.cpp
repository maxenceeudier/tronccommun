/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:53:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/28 10:24:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"
#include <iostream>

int main()
{
    {
        Weapon club = Weapon("crudespikedclub");
        HumanA bob("Bob",club);

        bob.attack();
        club.setType("someothertypeofclub");
        bob.attack();
        
    } 
    { 
        Weapon club = Weapon("crudespikedclub");
        HumanB jim("Jim");
        
        jim.setWeapon(club);
        jim.attack();
        club.setType("someothertypeofclub");
        jim.attack();
    }
    {
        std::cout << std::endl << std::endl;
        Weapon  arme_blanche = Weapon("sabre");
        Weapon  arme_a_feu = Weapon("pistolet");
        HumanA zombies("zombies", arme_blanche);
        HumanB humans("humans");
    
        zombies.attack();
        humans.attack();
        
        humans.setWeapon(arme_a_feu);
    
        zombies.attack();
        humans.attack();

        arme_a_feu.setType("fusils d'assault");
        arme_blanche.setType("hache");

        zombies.attack();
        humans.attack();

        humans.setWeapon(arme_blanche);
        arme_blanche.setType("katana");

        zombies.attack();
        humans.attack();
    }
    return (0);
}
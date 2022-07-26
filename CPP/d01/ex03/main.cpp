/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:53:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 12:50:01 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"

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
    return (0);
}
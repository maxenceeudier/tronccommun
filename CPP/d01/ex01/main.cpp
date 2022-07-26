/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 14:59:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *newZombie(std::string name)
{
    Zombie  *newzombie;

    newzombie = new Zombie(name);
    return (newzombie);
}

void    randomChump(std::string name)
{
    Zombie  randomchump = Zombie(name);
    
    randomchump.announce();
    return ;
}

int main()
{
    Zombie  *horde;
    int i = 0;

    horde = zombieHorde(10, "patric's horde");
    while (i < 10)
        (horde[i++]).announce();
    delete [] horde;
    return (0);
}
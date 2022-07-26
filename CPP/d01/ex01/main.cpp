/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 09:34:20 by maxenceeudi      ###   ########.fr       */
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

    horde = zombieHorde(10, "patric");
    while (i < 10)
        (horde[i++]).announce();
    delete [] horde;
    return (0);
}
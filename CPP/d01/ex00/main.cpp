/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 14:54:24 by meudier          ###   ########.fr       */
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
    Zombie *zomb;
    zomb = newZombie("zombie_on_heap");
    randomChump("zombie_on_stack");
    zomb->announce();
    delete zomb;
    return (0);
}
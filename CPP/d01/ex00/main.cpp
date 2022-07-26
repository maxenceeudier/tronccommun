/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 09:06:31 by maxenceeudi      ###   ########.fr       */
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
    zomb = newZombie("max");
    randomChump("sego");
    zomb->announce();
    delete zomb;
    return (0);
}
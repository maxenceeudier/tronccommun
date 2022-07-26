/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:10:25 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 09:42:22 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *zombiehorde;
    int     i;

    i = 0;
    zombiehorde = new Zombie[N];
    while (i < N)
        zombiehorde[i++].setname(name);
    return (zombiehorde);
}
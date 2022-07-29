/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:51:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 12:26:16 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
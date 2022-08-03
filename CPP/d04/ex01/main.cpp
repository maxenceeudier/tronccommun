/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:37:09 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:47:40 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main()
{

    std::cout << "Test du sujet :" << std::endl;
    Animal  *arrayOfAnimals[10];
    int     i;

    i = 0;
    while (i < 5)
        arrayOfAnimals[i++] = new Cat();
    while (i < 10)
        arrayOfAnimals[i++] = new Dog();
    i = 0;
    while (i < 10)
    {
        arrayOfAnimals[i]->makeSound();
        arrayOfAnimals[i]->getBrain()->getIdeas();
        delete arrayOfAnimals[i++];
    }
    std::cout << std::endl << std::endl;

    
    std::cout << "Test animal = animal :" << std::endl;
    Animal  *uno = new Dog();
    Animal  *laola = new Dog();
    
    uno->getBrain()->addIdeas("manger des lasagnes...");
    *laola = *uno;
    laola->getBrain()->getIdeas();
    laola->getBrain()->addIdeas("et nager !");
    uno->getBrain()->getIdeas();
    laola->getBrain()->getIdeas();
    delete uno;
    delete laola;
    std::cout << std::endl << std::endl;
    
    std::cout << "Test cpy cat :" << std::endl;
    Cat     a;
    Cat     b(a);
    
    a.getBrain()->addIdeas("nager");
    Cat     c(a);
    b.getBrain()->getIdeas();
    a.getBrain()->getIdeas();
    c.getBrain()->getIdeas();
    std::cout << std::endl << std::endl;

    std::cout << "Test cpy Animal :" << std::endl;
    Animal  q;
    Animal  w(q);
    q.makeSound();
    w.makeSound();
    
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:37:09 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 18:41:39 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal  a;
    std::cout << std::endl;
    const Cat     b;
    std::cout << std::endl;
    Dog     c;
    std::cout << std::endl;
    Animal  *d = new Dog();
    std::cout << std::endl;
    Cat  e = b;
    std::cout << std::endl << std::endl;
    a.makeSound();
    std::cout << std::endl;
    b.makeSound();
    std::cout << std::endl;
    c.makeSound();
    std::cout << std::endl;
    d->makeSound();
    std::cout << std::endl;
    e.makeSound();
    std::cout << std::endl;
    delete d;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "subject test" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;

    std::cout << std::endl;
    std::cout << "same test with WrongClass" << std::endl;
    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    wrongmeta->makeSound();
    delete k;
    delete wrongmeta;
    
    return (0);
}
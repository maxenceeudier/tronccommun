/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:19:06 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 17:44:30 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

Base    *generate(void)
{
    Base    *arrayData[3] = {
        new A(),
        new B(),
        new C()
    };
    srand((unsigned) time(NULL));
    int random = rand() % 3;
    int i = 0;
    while (i < 3)
    {
        if (i != random)
            delete arrayData[i];
        i++;
    }
    return (arrayData[random]);
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    return ;
}

void    identify(Base &p)
{
    try
    {
        A   a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        B   b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        C   c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
}

int main(int ac, char **av)
{
    (void)av;

    if (ac == 1)
    {
        Base *base = generate();    
        identify(base);
        identify(*base);
        delete base;
        return (0);
    }
    std::cout << "This programme don't take arguments" << std::endl;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:26:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/05 16:53:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  michel("michel", 150);
    
        std::cout << michel << std::endl;
        std::cout << michel-- << std::endl;
        std::cout << michel << std::endl;
        std::cout << michel++ << std::endl;
        std::cout << michel << std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat  michel("michel", 150);
    
        std::cout << michel << std::endl;
        michel.increment(100);
        std::cout << michel << std::endl;
        michel.decrement(50);
        std::cout << michel << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
         Bureaucrat  michel("michel", 1);
    
        std::cout << michel << std::endl;
        michel.decrement(100);
        std::cout << michel << std::endl;
        michel.increment(50);
        std::cout << michel << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat  michel("michel", 1);
    
        std::cout << michel << std::endl;
        michel.increment(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat  michel("michel", 150);
    
        std::cout << michel << std::endl;
        michel.decrement(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat  *micheline = new Bureaucrat("micheline", 1);
        
        std::cout << *micheline << std::endl;
        std::cout << (*micheline)++ << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat  mitch(Bureaucrat("Mitch", 0));
        std::cout << mitch << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat  mitch(Bureaucrat("Mitch", 0));
        std::cout << mitch << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    try
    {
        Bureaucrat  mutch("Mutch", 151);
        std::cout << mutch << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    return (0);
}
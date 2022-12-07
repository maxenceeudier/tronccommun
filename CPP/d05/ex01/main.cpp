/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:26:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 10:27:57 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat  patoch("patoch", 50);
        Form        G12("G12", 20, 1);
        
        patoch.signForm(G12);
        std::cout << G12;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat  patoch("patoch", 50);
        Form        G12("G12", 60, 1);
        
        patoch.signForm(G12);
        std::cout << G12;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat  patoch("patoch", 50);
        Form        G12("G12", 60, 1);
        {
           Form        G13 = G12;
           std::cout << G13;
        }
        patoch.signForm(G12);
        std::cout << G12;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat  patoch("patoch", 60);
        Form        G12("G12", 151, 1);
        
        patoch.signForm(G12);
        std::cout << G12;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat  patoch("patoch", 60);
        Form        G12("G12", 15, 0);
        
        patoch.signForm(G12);
        std::cout << G12;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:26:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 14:35:06 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm   jardin("jardin");
        {
        ShrubberyCreationForm   scf(jardin);
        }
        ShrubberyCreationForm   test("test");
        Bureaucrat              max("max", 2);
        Bureaucrat              lili("lili", 138);

        max.signForm(jardin);
        max.executeForm(jardin);
        lili.signForm(test);
        lili.executeForm(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;

    try
    {
        RobotomyRequestForm   rrf("42 school");
        Bureaucrat              max("max", 1);
        Bureaucrat              lili("lili", 45);
        Bureaucrat              paul("paul", 48);

        max.signForm(rrf);
        max.executeForm(rrf);
        lili.executeForm(rrf);
        paul.executeForm(rrf);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;


    try
    {
        PresidentialPardonForm  ppf("Maxence eudier");
        Bureaucrat              max("max", 1);
        Bureaucrat              lili("lili", 5);
        Bureaucrat              paul("paul", 8);

        max.signForm(ppf);
        max.executeForm(ppf);
        lili.signForm(ppf);
        lili.executeForm(ppf);
        paul.signForm(ppf);
        paul.executeForm(ppf);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    
    return (0);
}
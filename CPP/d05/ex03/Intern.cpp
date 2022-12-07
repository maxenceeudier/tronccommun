/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:51:57 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 15:43:16 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
    return ;
}

Intern::Intern(const Intern &intern)
{
    (void)intern;
    std::cout << "Intern cpy constructor called" << std::endl;
    return ;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
    return ;
}

Intern  &Intern::operator=(const Intern &intern)
{
    std::cout << "Intern assignement operator called" << std::endl;
    (void)intern;
    return (*this);
}

Form    *Intern::makeForm(std::string formName, std::string target)
{
    int i = 0;
    Form    *rslt = NULL;
    
    Form *arrayForm[3] = {
        new PresidentialPardonForm(target),
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target)
    };
    
    std::string arrayFormName[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"       
    };

    while (i < 3)
    {
        if (formName.compare(arrayFormName[i]) == 0)
            rslt = arrayForm[i];
        else
            delete arrayForm[i];
        i++;
    }
    
    if (!rslt)
        std::cout << "This form name doesn't exist. Intern can't create it" << std::endl;
    else
    {
        std::cout << "Intern create " << formName << " form with target ";
        std::cout << target << std::endl;
    }
    return (rslt);   
}
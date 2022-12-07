/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:26:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 15:48:28 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


int main()
{
    try
    {
        Intern  intern;
        Form    *rrf;
        Bureaucrat  max("max", 1);
    
        rrf = intern.makeForm("presidential pardon", "tintin");
        if (rrf)
        {
            max.signForm(*rrf);
            max.executeForm(*rrf);
            delete rrf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Intern  intern;
        Form    *rrf;
        Bureaucrat  max("max", 1);
    
        rrf = intern.makeForm("pardon", "tintin");
        if (rrf)
        {
            max.signForm(*rrf);
            max.executeForm(*rrf);
            delete rrf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
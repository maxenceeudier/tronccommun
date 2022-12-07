/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:04:34 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 14:31:14 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5),
_target("filename")
{
    std::cout << "PPForm default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5),
_target(target)
{
    std::cout << "PPForm with target constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : Form(cpy)
{
    std::cout << "PPForm cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PPForm destructor called" << std::endl;
    return ;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &rrf)
{
    std::cout << "If cpy constructor wasn't called only _target was copied" << std::endl;
    _target = rrf._target;
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (_target);
}

void  PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->checkExecute(executor);
    std::cout << "Zaphod Beeblebrox forgive " << _target << std::endl;
    return ;
}
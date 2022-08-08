/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:07:09 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 14:12:15 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::_isASucces = true;

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45),
_target("filename")
{
    std::cout << "RRForm default constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45),
_target(target)
{
    std::cout << "RRForm with target constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : Form(cpy)
{
    std::cout << "RRForm cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RRForm destructor called" << std::endl;
    return ;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    std::cout << "If cpy constructor wasn't called only _target was copied" << std::endl;
    _target = rrf._target;
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (_target);
}

void  RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->checkExecute(executor);
    std::cout << "BBZZZiiiTTT !!! bbbbbbrrrrrrRRRRRRRR !! bzut bzut" << std::endl;
    if (_isASucces)
        std::cout << _target << " is robotomised with succes !!" << std::endl;
    else
        std::cout << "Fail to robotomise " << _target << std::endl;
    _isASucces = !_isASucces;
    return ;
}
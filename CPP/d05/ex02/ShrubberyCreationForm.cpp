/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:06:50 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 13:57:27 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137),
_target("filename")
{
    std::cout << "SCForm default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137),
_target(target)
{
    std::cout << "SCForm with target constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : Form(cpy)
{
    std::cout << "SCForm cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "SCForm destructor called" << std::endl;
    return ;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    std::cout << "If cpy constructor wasn't called only _target was copied" << std::endl;
    _target = scf._target;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (_target);
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream   ofs(_target + "_shruberry");
    
    if (ofs.fail())
    {
        std::cout << "open permission denied" << std::endl;
        return ;
    }
    this->checkExecute(executor);
    ofs << "    \"  \"   \"  \"" << std::endl;
    ofs << "  (     \"    \"   )" << std::endl;
    ofs << " (                )" << std::endl;
    ofs << "(        \"    \"    )" << std::endl;
    ofs << " (                )" << std::endl;
    ofs << "  (  \\  ||  //   )" << std::endl;
    ofs << "   (  \\ || //   )" << std::endl;
    ofs << "       |  |   " << std::endl;
    ofs << "       |  |   " << std::endl;
    ofs << "       |  |   " << std::endl;
    ofs << "       |  |   " << std::endl;
    ofs << "       |  |   " << std::endl;
    ofs.close();
    return ;
}
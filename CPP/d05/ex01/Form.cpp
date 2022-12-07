/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:03:02 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 09:51:43 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("an other formulaire"), _sign(false), _gradeForSign(50),
_gradeForExec(1)
{
    std::cout << "Form default constructor called" << std::endl;
    return ;
}

Form::Form(const std::string name, const int sign, const int exec) : _name(name),
_sign(false), _gradeForSign(sign), _gradeForExec(exec)
{
    std::cout << "Form with params constructor called" << std::endl;
    if (_gradeForSign < 1 || _gradeForExec < 1)
        throw GradeTooHighException();
    if (_gradeForSign > 150 || _gradeForExec > 150)
        throw GradeTooLowException();
    return ;
}

Form::Form(const Form &cpy) : _name(cpy._name), _sign(cpy._sign),
_gradeForSign(cpy._gradeForSign), _gradeForExec(cpy._gradeForExec)
{
    std::cout << "Form cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Form    &Form::operator=(const Form &cpy)
{
    this->_sign = cpy._sign;
    std::cout << "Name and grades are const and can't be overwritten, ";
    std::cout << "if cpy constructor wasn't called only _sign was copied" << std::endl;
    return (*this);
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
    return ;
}

void    Form::beSigned(const Bureaucrat &brct)
{
    if (brct.getGrade() <= _gradeForSign)
        _sign = true;
    else
        throw GradeTooLowException();
    return ;
}

bool    Form::isSign(void) const
{
    return (_sign);
}

std::string   Form::getName(void) const
{
    return (_name);
}

int   Form::getGradeSign(void) const
{
    return (_gradeForSign);
}

int   Form::getGradeExec(void) const
{
    return (_gradeForExec);
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << "Name: " << form.getName() << std::endl;
    o << "Sign status: " << form.isSign() << std::endl;
    o << "Grade for sign: " << form.getGradeSign() << std::endl;
    o << "Grade for exec: " << form.getGradeExec() << std::endl;
    o << std::endl;
    return (o);
}


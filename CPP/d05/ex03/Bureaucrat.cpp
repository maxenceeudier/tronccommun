/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:10:03 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 13:43:49 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("mec lamda"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat with params constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
    std::cout << "Bureaucrat cpy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
    return ;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &bureaucrat2)
{
    std::cout << "Bureaucrat assignement operator called" << std::endl;
    _name = bureaucrat2._name;
    _grade = bureaucrat2._grade;
    return (*this);
}

Bureaucrat  Bureaucrat::operator++(int)
{
    Bureaucrat  temp;
    temp = *this;

    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
    return (temp);
}

Bureaucrat  Bureaucrat::operator--(int)
{
    Bureaucrat  temp;
    temp = *this;

    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
    return (temp);
}

Bureaucrat  &Bureaucrat::increment(int grade)
{
    if (_grade - grade <= 0)
        throw GradeTooHighException();
    else
        _grade -= grade;
    return (*this);
}

Bureaucrat  &Bureaucrat::decrement(int grade)
{
    if (_grade + grade > 150)
        throw GradeTooLowException();
    else
        _grade += grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureau)
{
    o << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
    return (o);
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void        Bureaucrat::signForm(Form &form)
{
    if (_grade <= form.getGradeSign())
        std::cout << _name << " signed " << form.getName() << std::endl;
    else
    {
        std::cout << _name << " could't sign ";
        std::cout << form.getName() << " because ";
        std::cout << " his grade is under " << form.getGradeSign() << std::endl;
    }
    form.beSigned(*this);
}

void        Bureaucrat::executeForm(Form const &form)
{
    if (_grade <= form.getGradeExec())
        std::cout << _name << " execute " << form.getName() << std::endl;
    else
    {
        std::cout << _name << " couldn't execute ";
        std::cout << form.getName() << " because ";
        std::cout << " his grade is under " << form.getGradeSign() << std::endl;
    }
    form.execute(*this);
}
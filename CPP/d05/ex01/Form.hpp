/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:58:04 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 10:03:06 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool              _sign;
    const int         _gradeForSign;
    const int         _gradeForExec;
    Form(void);
public:
    Form(const std::string name, const int gradeForSign, const int gradeForExec);
    Form(const Form &cpy);
    ~Form(void);
    Form    &operator=(const Form &form2);

    void          beSigned(const Bureaucrat &brct);
    bool          isSign(void) const;
    std::string   getName(void) const;
    int           getGradeSign(void) const;
    int           getGradeExec(void) const;
    

    class   GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Too high grade. It must be between 1 and 150.");
            }
    };
    class   GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Too low grade. It must be between 1 and 150.");
            }
    };
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif
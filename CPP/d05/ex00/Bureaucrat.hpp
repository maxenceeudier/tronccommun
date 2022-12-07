/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:11:00 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/05 16:45:54 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class   Bureaucrat
{
    private:
        std::string _name;
        int         _grade;
        Bureaucrat(void);
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &cpy);
        ~Bureaucrat(void);
        Bureaucrat  &operator=(const Bureaucrat &bureaucrat2);

        std::string getName(void) const;
        int         getGrade(void) const;
        Bureaucrat  operator++(int);
        Bureaucrat  operator--(int);
        Bureaucrat  &increment(int grade);
        Bureaucrat  &decrement(int grade);
        
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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureau);


#endif
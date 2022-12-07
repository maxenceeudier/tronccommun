/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:06:15 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 14:07:50 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
#define RRF_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{  
    private:
        std::string _target;
        RobotomyRequestForm(void);
        static bool _isASucces;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm   &operator=(const RobotomyRequestForm &scf);

        std::string getTarget(void) const;
        virtual void  execute(Bureaucrat const &executor) const;
};

#endif
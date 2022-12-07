/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:05:31 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 14:28:01 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPF_HPP
#define PPF_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form
{  
    private:
        std::string _target;
        PresidentialPardonForm(void);
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm   &operator=(const PresidentialPardonForm &scf);

        std::string getTarget(void) const;
        virtual void  execute(Bureaucrat const &executor) const;
};

#endif
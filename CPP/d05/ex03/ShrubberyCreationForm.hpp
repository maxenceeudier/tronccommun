/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:06:32 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/08 13:43:41 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCF_HPP
#define SCF_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{  
    private:
        std::string _target;
        ShrubberyCreationForm(void);
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &scf);

        std::string getTarget(void) const;
        virtual void  execute(Bureaucrat const &executor) const;
};

#endif
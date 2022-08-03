/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:33:28 by meudier           #+#    #+#             */
/*   Updated: 2022/08/03 16:54:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

Brain::Brain(void)
{
    if (PRINT)
        std::cout << "Brain default constructor called" << std::endl;
    int i = 0;
    while (i < 100)
        _ideas[i++] = "";
    return ;    
}

Brain::Brain(const Brain &cpy)
{
    if (PRINT)
        std::cout << "Brain cpy constructor called" << std::endl;
    *this = cpy;
    return ;    
}

Brain::~Brain(void)
{
    if (PRINT)
        std::cout << "Brain destructor called" << std::endl;
    return ;    
}

Brain   &Brain::operator=(const Brain &brain2)
{
    if (PRINT)
        std::cout << "Brain assignement operator called" << std::endl;
    int i = 0;
    while (i < 100 && (brain2._ideas[i]).compare("") != 0)
    {
        _ideas[i] = brain2._ideas[i];
        i++;
    }  
    return (*this);
}

void    Brain::addIdeas(std::string newIdea)
{
    int i = 0;
    while (i < 100)
    {
        if (_ideas[i].compare("") == 0)
        {
            _ideas[i] = newIdea;
            return ;
        }
        else
            i++;
    }
    std::cout << "My brain is to small to have this idea" << std::endl;
    return ;
}

void    Brain::getIdeas(void)
{
    int i = 0;

    std::cout << "I love ";
    while (i < 99 && _ideas[i + 1].compare("") != 0)
        std::cout << _ideas[i++] << ", ";
    if ((i == 99 && _ideas[i + 1].compare("") == 0) || (i != 99 && !(_ideas[i + 1].compare("") != 0)))
        std::cout << _ideas[i] << std::endl;
    return ;
}
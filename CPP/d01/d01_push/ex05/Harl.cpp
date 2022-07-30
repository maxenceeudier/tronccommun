/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:42:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/28 10:55:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
   return ;
}

Harl::~Harl()
{
    return ;
}

void    Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon ";
    std::cout << "for my 7XL-double-cheese-triple-pickle-specialketchup";
    std::cout << "burger. I really do!" << std::endl;
    return ;
}
    
void    Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs ";
    std::cout << "more money. You didn’t put enough bacon in ";
    std::cout << "my burger! If you did, I wouldn’t be asking ";
    std::cout << "for more!" << std::endl;
    return ;
}

void    Harl::warnig(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for ";
    std::cout << "free. I’ve been coming for years whereas you started";
    std::cout << " working here since last month." << std::endl;
    return ;
}
    
void    Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the ";
    std::cout << "manager now." << std::endl;
    return ;
}

void    Harl::complain(std::string level)
{
    int i;

    i = 0;
    void    (Harl::*f[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warnig,
        &Harl::error
    };
    std::string lev[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    while (i < 4 && level.data())
    {
        if (level.compare(lev[i]) == 0)
        {
            (this->*f[i])();
            return ;
        }   
        i++;
    }
    std::cout << "Sorry i don't know this level" << std::endl;
}
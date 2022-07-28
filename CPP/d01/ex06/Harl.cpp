/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:42:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/28 10:57:57 by meudier          ###   ########.fr       */
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
    std::cout << "[WARNIG]" << std::endl;
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
    
    while (level.data() && i < 4)
    {
        if (level == lev[i])
            break ;
        i++;
    }
    
    switch (i)
    {
        case  0:
            i = 1;
            break;
        case 1:
            i = 2;
            break;
        case 2:
            i = 3;
            break;
        case 3:
            i = 4;
            break;
        default:
            i = 0;
            break;
    }
    
    while (i && i < 5)
        (this->*f[i++ - 1])();
    
    if (!i)
        std::cout << "[Probably complaining about insignificant problems]" << std::endl;
}
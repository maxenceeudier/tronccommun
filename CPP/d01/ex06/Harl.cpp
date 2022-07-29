/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:42:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:58:44 by meudier          ###   ########.fr       */
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
    int level_type;
        
    i = 0;
    level_type = 0;
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
    
    while (level.data() && level_type < 4)
    {
        if (level == lev[level_type])
            break ;
        level_type++;
    }
    
    switch (level_type)
    {
        case  DEBUG_TYPE:
            i = 1;
            break;
        case INFO_TYPE:
            i = 2;
            break;
        case WARNING_TYPE:
            i = 3;
            break;
        case ERROR_TYPE:
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
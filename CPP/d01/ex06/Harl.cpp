/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:42:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 17:39:19 by meudier          ###   ########.fr       */
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
    std::cout << "debug msssg" << std::endl << std::endl;
    return ;
}
    
void    Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "info msssg" << std::endl << std::endl;
    return ;
}

void    Harl::warnig(void)
{
    std::cout << "[WARNIG]" << std::endl;
    std::cout << "warning msssg" << std::endl << std::endl;
    return ;
}
    
void    Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "error msssg" << std::endl << std::endl;
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
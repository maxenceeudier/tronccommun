/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:42:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 16:26:24 by meudier          ###   ########.fr       */
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
    std::cout << "debug msssg" << std::endl;
    return ;
}
    
void    Harl::info(void)
{
    std::cout << "info msssg" << std::endl;
    return ;
}

void    Harl::warnig(void)
{
    std::cout << "warning msssg" << std::endl;
    return ;
}
    
void    Harl::error(void)
{
    std::cout << "error msssg" << std::endl;
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
        "debug",
        "info",
        "warning",
        "error"
    };
    while (i < 4 && level.c_str())
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
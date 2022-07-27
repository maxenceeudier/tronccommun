/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:26 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/27 18:28:26 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

Contact::Contact()
{
    return ;
}

Contact::~Contact()
{
    return ;
}

void    Contact::printContact()
{
    std::cout << " ---------------------------------- " << std::endl;
    std::cout << "     " << this->firstName << " " << this->lastName;
    std::cout << "     " << std::endl;
    std::cout << " ---------------------------------- " << std::endl;
    std::cout << "firstname      : " << this->firstName << std::endl;
    std::cout << "lastname       : " << this->lastName << std::endl;
    std::cout << "nickname       : " << this->nickName << std::endl;
    std::cout << "darkest secret : " << this->darkestSecret << std::endl;
    std::cout << "phone number   : " << this->phoneNumber << std::endl << std::endl;
    return ;
}

void    Contact::setContact()
{
    std::cout << "firstname      : " << std::endl;
    std::getline(std::cin, this->firstName);
    std::cout << "lastname       : " << std::endl;
    std::getline(std::cin, this->lastName);
    std::cout << "nickname       : " << std::endl;
    std::getline(std::cin, this->nickName);
    std::cout << "darkest secret : " << std::endl;
    std::getline(std::cin, this->darkestSecret);
    std::cout << "phone number   : " << std::endl;
    std::getline(std::cin, this->phoneNumber);
    std::cout << std::endl;
    return ;
}

bool    Contact::isPhoneNum(std::string &str)
{
    int i;

    i = 0;
    if (!str.size() || str.size() != 10)
        return (false);
    while (str[i])
        if (std::isdigit(str[i++]) == 0)
            return (false);
    return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:26 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/12 10:39:22 by maxenceeudi      ###   ########.fr       */
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
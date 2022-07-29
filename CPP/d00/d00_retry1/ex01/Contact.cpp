/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:26 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:36:42 by meudier          ###   ########.fr       */
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
    std::cout << "     " << this->_firstName << " " << this->_lastName;
    std::cout << "     " << std::endl;
    std::cout << " ---------------------------------- " << std::endl;
    std::cout << "firstname      : " << this->_firstName << std::endl;
    std::cout << "lastname       : " << this->_lastName << std::endl;
    std::cout << "nickname       : " << this->_nickName << std::endl;
    std::cout << "darkest secret : " << this->_darkestSecret << std::endl;
    std::cout << "phone number   : " << this->_phoneNumber << std::endl << std::endl;
    return ;
}

void    Contact::setContact()
{
    std::cout << "firstname      : " << std::endl;
    if (!std::getline(std::cin, this->_firstName))
        return ;
    std::cout << "lastname       : " << std::endl;
    if (!std::getline(std::cin, this->_lastName))
        return ;
    std::cout << "nickname       : " << std::endl;
    if (!std::getline(std::cin, this->_nickName))
        return ;
    std::cout << "darkest secret : " << std::endl;
    if (!std::getline(std::cin, this->_darkestSecret))
        return ;
    std::cout << "phone number   : " << std::endl;
    if (!std::getline(std::cin, this->_phoneNumber))
        return ;
    std::cout << std::endl;
    return ;
}

std::string     Contact::getFirstName(void)
{
    return (Contact::_firstName);
}

std::string     Contact::getLastName(void)
{
    return (Contact::_lastName);
}
    
std::string     Contact::getNickName(void)
{
    return (Contact::_nickName);
}

std::string		Contact::getDarkestSecret(void)
{
    return (Contact::_darkestSecret);
}

std::string		Contact::getPhoneNumber(void)
{
    return (Contact::_phoneNumber);
}
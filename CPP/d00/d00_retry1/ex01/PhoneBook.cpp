/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:34:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:35:26 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

PhoneBook::PhoneBook()
{
    return ;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void    PhoneBook::addContacts(Contact contact)
{
    int i;

    if (this->_nbOfContact == 8)
    {
        std::cout << "too many contacts" << std::endl << std::endl;
        i = 0;
        while (i < this->_nbOfContact - 1)
        {
            this->_contacts[i] = this->_contacts[i + 1];
            i++;
        }
        this->_contacts[i] = contact;
    }  
    else
    {
        this->_contacts[this->_nbOfContact] = contact;
        this->set_nb_of_contact();
    }  
    return ;
}

void    PhoneBook::set_nb_of_contact(void)
{
    PhoneBook::_nbOfContact++;
    return ;
}

std::string PhoneBook::reduce(std::string str)
{
    std::string space;
    int         size;
    int         i;

    space = "";
    size = str.size();
    i = size;
    if (size == 10)
        return (str);
    else if (size < 10)
    {
        while (i < 10)
        {
            space += " ";
            i++;
        }
    }
    else
    {
        str = str.substr(0, 9) + ".";
    }
    return (space + str);
}

void    PhoneBook::printContatcs(void)
{
    int         i;
    int         index;
    std::string temp;

    i = 0;
    while (i < this->_nbOfContact)
    {
        std::cout << "|      " << i + 1 << "     | ";  
        std::cout << this->reduce(this->_contacts[i].getFirstName()) << " | ";
        std::cout << this->reduce(this->_contacts[i].getLastName()) << " | ";
        std::cout << this->reduce(this->_contacts[i].getNickName()) << " |" << std::endl;
        std::cout << " --------------------------------------------------- " << std::endl;
        i++;
    }
    std::cout << std::endl << std::endl;
    if (this->_nbOfContact == 0)
    {
        std::cout << "PHONEBOOK IS EMPTY" << std::endl;
        std::cout << std::endl;
        return ;
    }
    std::cout <<"ENTER THE INDEX OF A CONTACT OR ENTER TO GO BACK IN HOME" << std::endl;
    if (!std::getline(std::cin, temp))
        return ;
    index = std::atoi(temp.c_str());
    if (index > 0 && index <= this->_nbOfContact)
        _contacts[index - 1].printContact();
    else
        std::cout << "WRONG INDEX" << std::endl << std::endl;
    return ;
}

int PhoneBook::_nbOfContact = 0;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:34:56 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 14:22:02 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

PhoneBook::PhoneBook() : nb_of_contact(0)
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

    if (this->get_nb_of_contact() == 8)
    {
        std::cout << "too many contacts" << std::endl << std::endl;
        i = 0;
        while (i < this->get_nb_of_contact() - 1)
        {
            (this->contacts[i]).~Contact();
            this->contacts[i] = this->contacts[i + 1];
            i++;
        }
        this-> contacts[i] = contact;
    }  
    else
    {
        this->contacts[this->get_nb_of_contact()] = contact;
        this->set_nb_of_contact();
    }  
    return ;
}

void    PhoneBook::set_nb_of_contact(void)
{
    PhoneBook::nb_of_contact++;
    return ;
}

int     PhoneBook::get_nb_of_contact(void)
{
    return (PhoneBook::nb_of_contact);
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
    std::string temp;
    int         index;

    i = 0;
    while (i < this->get_nb_of_contact())
    {
        std::cout << "|      " << i + 1 << "     | ";  
        std::cout << this->reduce(this->contacts[i].firstName) << " | ";
        std::cout << this->reduce(this->contacts[i].lastName) << " | ";
        std::cout << this->reduce(this->contacts[i].nickName) << " |" << std::endl;
        std::cout << " --------------------------------------------------- " << std::endl;
        i++;
    }
    std::cout << std::endl << std::endl;
    if (this->get_nb_of_contact() == 0)
    {
        std::cout << "PHONEBOOK IS EMPTY" << std::endl;
        std::cout << std::endl;
        return ;
    }
    std::cout <<"ENTER THE INDEX OF A CONTACT" << std::endl;
    std::getline(std::cin, temp);
    index = std::atoi(temp.c_str());
    if (index > 0 && index <= this->get_nb_of_contact())
        contacts[index - 1].printContact();
    else
        std::cout << "WRONG INDEX" << std::endl << std::endl;
    return ;
}
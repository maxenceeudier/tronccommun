/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:34:42 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/27 18:35:52 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include.h"

int main(int ac, char **av)
{
    (void)av;
    int         exit;
    std::string input;
    PhoneBook   repertoire;

    if (ac != 1)
        return (1);
    exit = 1;
    while (exit)
    {
        std::cout << "ENTER A CMD : (ADD | SEARCH | EXIT)" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::getline(std::cin, input);
        std::cout << std::endl;
        if (input.compare("EXIT") == 0)
            exit = 0;
        else if (input.compare("ADD") == 0)
        {
            std::locale loc;
            Contact contact;
            contact.setContact();
            if (!contact.firstName.size() || !contact.lastName.size()
                || !contact.nickName.size() || !contact.darkestSecret.size())
            {
                contact.~Contact();
                std::cout << "Error: empty input" << std::endl << std::endl;
            }
            else if (!Contact::isPhoneNum(contact.phoneNumber))
            {
                contact.~Contact();
                std::cout << "Phone number not conform: ";
                std::cout << "format accept: num x10";
                std::cout << std::endl << std::endl;
            }
            else
                repertoire.addContacts(contact);
        } 
        else if (input.compare("SEARCH") == 0)
        {
            std::cout << " --------------------------------------------------- " << std::endl;
            std::cout << "|    INDEX   |  FIRSTNAME |  LASTNAME  |   NICKNAME |" << std::endl;
            std::cout << " --------------------------------------------------- " << std::endl;
            repertoire.printContatcs();
        }
        else
            std::cout << "BAD CMD TRY AGAIN" << std::endl << std::endl;
    }
    return (0);
}
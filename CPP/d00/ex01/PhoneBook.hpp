/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:10 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:35:21 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include "include.h"

class PhoneBook
{
private:
    static int  _nbOfContact;
    std::string reduce(std::string str);
    Contact     _contacts[8];
public:
    PhoneBook();
    ~PhoneBook();

    void        printContatcs(void);
    void        addContacts(Contact contact);
    static void set_nb_of_contact(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:10 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/27 18:06:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include "include.h"

class PhoneBook
{
private:
    static int nb_of_contact;
    std::string reduce(std::string str);
    Contact     contacts[8];
public:
    PhoneBook();
    ~PhoneBook();

    void        printContatcs(void);
    void        addContacts(Contact contact);
    static void set_nb_of_contact(void);
    static int  get_nb_of_contact(void);
};

#endif
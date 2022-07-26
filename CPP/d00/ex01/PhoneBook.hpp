/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:10 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/12 10:27:05 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include "include.h"

class PhoneBook
{
private:
    int nb_of_contact;
public:
    PhoneBook();
    ~PhoneBook();

    Contact contacts[8];
    void        printContatcs(void);
    void        addContacts(Contact contact);
    std::string reduce(std::string str);
    void        set_nb_of_contact(void);
    int         get_nb_of_contact(void);
};

#endif
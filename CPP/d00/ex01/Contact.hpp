/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:36:37 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include "include.h"

class Contact
{
public:
    Contact();
    ~Contact();

    void            printContact(void);
    void            setContact(void);
    std::string     getFirstName(void);
    std::string     getLastName(void);
    std::string     getNickName(void);
    std::string		getDarkestSecret(void);
    std::string		getPhoneNumber(void);

private:
    std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_phoneNumber;
	std::string		_darkestSecret;
};

#endif
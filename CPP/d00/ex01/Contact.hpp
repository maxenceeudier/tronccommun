/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/27 18:28:21 by meudier          ###   ########.fr       */
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

    std::string		firstName;
	std::string		lastName;
	std::string		nickName;
	std::string		phoneNumber;
	std::string		darkestSecret;
    
    void    printContact(void);
    void    setContact(void);
    static bool    isPhoneNum(std::string &str);
};

#endif
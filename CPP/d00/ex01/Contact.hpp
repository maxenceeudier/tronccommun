/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/11 16:47:12 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include "include.h"

class Contact
{
private:
    /* data */
public:
    Contact(void);
    ~Contact();

    std::string		firstName;
	std::string		lastName;
	std::string		nickName;
	std::string		phoneNumber;
	std::string		darkestSecret;
    
    void    printContact(void);
    void    setContact(void);
};

#endif
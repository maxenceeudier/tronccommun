/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:06:39 by meudier           #+#    #+#             */
/*   Updated: 2022/10/13 16:21:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_STRING_HPP
#define TO_STRING_HPP
#include <string>
#include <iostream>
#include <sstream>

namespace ft
{
    template <typename T>
    std::string to_string(T &data)
    {
        std::string Result;          // string which will contain the result

        std::ostringstream convert;   // stream used for the conversion

        convert << data;      // insert the textual representation of 'Number' in the characters in the stream

        Result = convert.str(); 

        return (Result);
    }; 
}

#endif
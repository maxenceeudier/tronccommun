/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:47 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 17:09:39 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string str;
    int         n;
};

uintptr_t   serialize(Data *ptr);
Data        *deserialize(uintptr_t raw);

#endif
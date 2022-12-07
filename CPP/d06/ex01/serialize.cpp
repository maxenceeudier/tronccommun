/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:38 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 16:58:31 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

uintptr_t   serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
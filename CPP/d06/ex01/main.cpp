/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:00:05 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/09 17:11:15 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int main()
{
    Data data;
    data.n = 42;
    data.str = "test";
    uintptr_t   raw = serialize(&data);
    Data        *test = deserialize(raw);

    std::cout << test->str << std::endl;
    std::cout << test->n << std::endl;
}
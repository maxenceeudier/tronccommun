/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:06:42 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/06 14:15:35 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector/basic_function.hpp"
#include "../srcs/vector/capacity.hpp"
#include "../srcs/vector/iterators.hpp"
#include "../srcs/vector/modifiers.hpp"
#include "../srcs/vector/vector.hpp"
#include <iostream>

int test_vector()
{
    ft::vector<int> test1;

    test1.push_back(2);
    test1.push_back(6);
    std::cout << test1;
    test1.pop_back();
    std::cout << test1;

    
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:55:12 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/10 10:39:35 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::string tab1[3] = {"bonjour", "comment", "ca va ?"};
    int         tab2[5] = {1, 2, 3, 4, 5};
    float       tab3[7] = {42.0f, 21, 3.6f, 2, 5, 4.7654f, 3.3333};

    ::iter<std::string, void>(tab1, 3, ::print);
    std::cout << std::endl << std::endl;
    ::iter<int, void>(tab2, 5, ::print);
    std::cout << std::endl;
    ::iter<int, int>(tab2, 5, ::increment);
    std::cout << std::endl;
    ::iter<int, void>(tab2, 5, ::print);
    std::cout << std::endl << std::endl;
    ::iter<float, void>(tab3, 7, ::print);
    std::cout << std::endl;
    ::iter<float, int>(tab3, 7, ::increment);
    std::cout << std::endl;
    ::iter<float, void>(tab3, 7, ::print);
    
    return (0);
}
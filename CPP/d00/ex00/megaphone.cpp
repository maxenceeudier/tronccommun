/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:56:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:14:32 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    int             i;
    unsigned long   j;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        i = 1;
        while (i < ac)
        {
            std::string str = av[i++];
            j = 0;
            while (j < str.size())
                std::cout << (char)(std::toupper(str[j++]));
        }
        std::cout << std::endl;
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:49:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/13 22:20:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map/map.h"
#include <string>
#include <map>

void test_map()
{
    std::map<std::string, int> map;
    map.insert(std::pair<std::string, int>("hello1", 3));
    map.insert(std::pair<std::string, int>("hello2", 3));
    map.insert(std::pair<std::string, int>("hello3", 3));
    map.insert(std::pair<std::string, int>("hello4", 3));

    
    std::map<std::string, int>::iterator it = map.begin();
    while (it != map.end())
    {
        std::cout << "key: " << it->first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
        it++;
    }
    std::cout << map.size();
    std::cout << std::endl;

    ft::map<std::string, int> map2;


    map2.insert(ft::pair<std::string, int>("hello1", 3));
    map2.insert(ft::pair<std::string, int>("hello1", 10));
    map2.insert(ft::pair<std::string, int>("hello1", 3));
    map2.insert(ft::pair<std::string, int>("hello3", 3));
    map2.insert(ft::pair<std::string, int>("hello4", 3));

    std::cout << map2;
    
}

int main()
{
    test_map();
    return (0);
}
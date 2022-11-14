/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:49:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/14 17:08:12 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map/map.h"
#include <string>
#include <map>

void test_map()
{
    std::map<std::string, int> map;
    map.insert(std::pair<std::string, int>("hello1", 3));
    map.insert(std::pair<std::string, int>("hello1", 3));
    map.insert(std::pair<std::string, int>("hello3", 5));
    map.insert(std::pair<std::string, int>("hello4", 3));
    map.insert(std::pair<std::string, int>("hello2", 3));

    
    std::map<std::string, int>::iterator it = map.begin();
    while (it != map.end())
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
        it++;
    }

    //test it en cours
    std::cout << std::endl << "test it:\n";
    it = map.begin();
    it--;
    it--;
 
    std::cout << "key: " << it->first;
    std::cout << " value: " << it->second;
    std::cout << std::endl << std::endl;
    it = map.end();
    it++;
    it++;
    it++;

    std::cout << "key: " << it->first;
    std::cout << " value: " << it->second;
    std::cout << std::endl << std::endl;
    
    std::cout << "map.size() : " << map.size() << std::endl;
    std::cout << "map.max_size() : " << map.max_size() << std::endl;
    std::cout << "map.empty() : " << map.empty() << std::endl;


    std::cout << "map.at(hello1) : " << map.at("hello1") << std::endl;
    std::cout << "map[hello3] : " << map["hello3"] <<  std::endl;

    std::cout << "map.count(\"hello2\") : " << map.count("hello2") <<  std::endl;
    std::cout << "map.count(\"hello10\") : " << map.count("hello10") <<  std::endl;


    std::cout << "\n\nrbegin() && rend() : \n";
    for (std::map<std::string, int>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }

    std::cout << std::endl;



    ft::map<std::string, int> map2;


    map2.insert(ft::pair<std::string, int>("hello1", 3));
    map2.insert(ft::pair<std::string, int>("hello1", 10));
    map2.insert(ft::pair<std::string, int>("hello3", 5));
    map2.insert(ft::pair<std::string, int>("hello4", 3));
    map2.insert(ft::pair<std::string, int>("hello2", 3));

    ft::map<std::string, int>::iterator itf = map2.begin();
    
    while (itf != map2.end())
    {
        std::cout << "key: " << itf->first;
        std::cout << " value: " << itf->second;
        std::cout << std::endl;
        itf++;
    }

    //std::cout << map2;

    std::cout << std::endl << "test it:\n";
    itf = map2.begin();
    itf--;
    itf--;

    std::cout << "key: " << itf->first;
    std::cout << " value: " << itf->second;
    std::cout << std::endl << std::endl;

    itf = map2.end();
    itf++;
    itf++;
    itf++;
 
    std::cout << "key: " << itf->first;
    std::cout << " value: " << itf->second;
    std::cout << std::endl << std::endl;
    

    std::cout << "map.size() : " << map2.size() << std::endl;
    std::cout << "map.max_size() : " << map2.max_size() << std::endl;
    std::cout << "map.empty() : " << map2.empty() << std::endl;
    

    std::cout << "map.at(hello1) : " << map2.at("hello1") << std::endl;
    std::cout << "map[hello3] : " << map2["hello3"] <<  std::endl;

    std::cout << "map.count(\"hello2\") : " << map2.count("hello2") <<  std::endl;
    std::cout << "map.count(\"hello10\") : " << map2.count("hello10") <<  std::endl;

    std::cout << "\n\nrbegin() && rend() : \n";
    for (typename ft::map<std::string, int>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
    {
        std::cout << "key: " << it->first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    
}

int main()
{
    test_map();
    return (0);
}
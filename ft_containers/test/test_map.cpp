/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:49:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/15 17:04:45 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map/map.h"
#include <string>
#include <map>

void test_map()
{
    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*          STD             */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
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
    std::map<std::string, int>::reverse_iterator it2;
    it2 = map.rend();
    it2++;
    it2++;
    it2++;

    std::cout << "key: " << it->first;
    std::cout << " value: " << it->second;
    std::cout << std::endl << std::endl;
    
    std::cout << "map.size() : " << map.size() << std::endl;
    std::cout << "map.max_size() : " << map.max_size() << std::endl;
    std::cout << "map.empty() : " << map.empty() << std::endl;


    std::cout << "map.at(hello1) : " << map.at("hello1") << std::endl;
    std::cout << "map[hello3] : " << map["hello3"] <<  std::endl;
    std::cout << "map[hello10] : " << map["hello10"] <<  std::endl;

    std::cout << "map.count(\"hello2\") : " << map.count("hello2") <<  std::endl;
    std::cout << "map.count(\"hello10\") : " << map.count("hello10") <<  std::endl;



     std::cout << "\n\nbegin() && end() : \n";
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nrbegin() && rend() : \n";
    for (std::map<std::string, int>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nC_begin() && C_rend() : \n";
    for (std::map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nCR_begin() && CR_end() : \n";
    for (std::map<std::string, int>::const_reverse_iterator it = map.rbegin(); it != map.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;



    std::cout << "\nmap.clear()\n";
    map.clear();
    std::cout << "\n\nbegin() && end() : \n";
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }

    std::cout << "\n\nmap.insert(value)\n\n";
    std::pair<std::map<std::string, int>::iterator , bool> rtr;
    map.insert(std::pair<std::string, int>("hello1", 1));
    map.insert(std::pair<std::string, int>("hello3", 3));
    map.insert(std::pair<std::string, int>("hello4", 4));
    rtr = map.insert(std::pair<std::string, int>("hello2", 2));
    std::cout << "rtr : " << rtr.first->first << " " << rtr.second << std::endl;
    rtr = map.insert(std::pair<std::string, int>("hello2", 2));
    std::cout << "rtr : " << rtr.first->first << " " << rtr.second << std::endl;


    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*          FT              */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

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

    ft::map<std::string, int>::reverse_iterator itf2;
    itf2 = map2.rend();
    itf2++;
    itf2++;
    itf2++;
 
    std::cout << "key: " << itf->first;
    std::cout << " value: " << itf->second;
    std::cout << std::endl << std::endl;
    

    std::cout << "map.size() : " << map2.size() << std::endl;
    std::cout << "map.max_size() : " << map2.max_size() << std::endl;
    std::cout << "map.empty() : " << map2.empty() << std::endl;
    

    std::cout << "map.at(hello1) : " << map2.at("hello1") << std::endl;
    std::cout << "map[hello3] : " << map2["hello3"] <<  std::endl;
    std::cout << "map[hello10] : " << map2["hello10"] <<  std::endl;

    std::cout << "map.count(\"hello2\") : " << map2.count("hello2") <<  std::endl;
    std::cout << "map.count(\"hello10\") : " << map2.count("hello10") <<  std::endl;

    std::cout << "\n\nbegin() && end() : \n";
    for (ft::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nrbegin() && rend() : \n";
    for (ft::map<std::string, int>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "\n\nC_begin() && C_rend() : \n";
    /*for (ft::map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }*/
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nCR_begin() && CR_end() : \n";
    /*for (ft::map<std::string, int>::const_reverse_iterator it = map.rbegin(); it != map.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }*/
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "\nmap.clear()\n";
    map2.clear();
    std::cout << "\n\nbegin() && end() : \n";
    for (ft::map<std::string, int>::iterator it = map2.begin() + 6; it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }


    std::cout << "\n\nmap.insert(value)\n\n";
    ft::pair<ft::map<std::string, int>::iterator , bool> rtr2;
    map2.insert(ft::pair<std::string, int>("hello1", 1));
    map2.insert(ft::pair<std::string, int>("hello3", 3));
    map2.insert(ft::pair<std::string, int>("hello4", 4));
    rtr2 = map2.insert(ft::pair<std::string, int>("hello2", 2));
    std::cout << "rtr : " << rtr2.first->first << " " << rtr2.second << std::endl;
    rtr2 = map2.insert(ft::pair<std::string, int>("hello2", 2));
    std::cout << "rtr : " << rtr2.first->first << " " << rtr2.second << std::endl;
    
    
    
}

    

int main()
{
    test_map();
    return (0);
}
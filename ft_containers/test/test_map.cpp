/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:49:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/16 15:15:39 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map/map.h"
#include <string>
#include <map>

void print(ft::Node<ft::pair<std::string, int> > *root)
{
    if (!root)
        return ;
    if (root->parent)
        std::cout << "parent: " << root->parent->data.first << std::endl;
    if (root->left)
        std::cout << "left: " << root->left->data.first << std::endl;
    if (root->right)
        std::cout << "rigth: " << root->right->data.first << std::endl;
    std::cout << "data: " << root->data.first << std::endl;
    std::cout << std::endl << std::endl;
    print(root->left);
    print(root->right);
}

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

    std::cout << "\n\nmapSwap : \n\n";
    std::map<std::string, int> mapSwap;
    mapSwap.swap(map);
    for (std::map<std::string, int>::iterator it = mapSwap.begin(); it != mapSwap.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << "\n\n";

    map.swap(mapSwap);
    std::map<std::string, int>::iterator i = map.begin();
    i++;
    i++;
    
    i = map.insert(i, std::pair<std::string, int>("hello10", 10));
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << "i: " << i->first << std::endl;

    std::cout << "map.erase(hello10) : " << map.erase("hello10") << std::endl;
    std::cout << "map.erase(hello10) : " << map.erase("hello10") << std::endl;

    std::cout << "\n\nerase(iterator pos):\n";
    map.erase(++map.begin());
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }

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
    for (ft::map<std::string, int>::iterator it = map2.begin() ; it != map2.end(); it++)
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

    for (ft::map<std::string, int>::iterator it = map2.begin() ; it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    
    
    std::cout << "\n\nmapSwap : \n\n";
    ft::map<std::string, int> mapSwap2;

    mapSwap2.swap(map2);

    
    std::cout << "mapSwap2: \n";
    for (ft::map<std::string, int>::iterator it = mapSwap2.begin(); it != mapSwap2.end(); it++)
    {
        std::cout << "key: " << it->first << std::endl; 
    }
    std::cout << "map2: \n";
    for (ft::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << it->first << std::endl; 
    }

    map2.swap(mapSwap2);
    
    ft::map<std::string, int>::iterator i2 = map2.begin();
    i2++;
    i2++;
    
    i2 = map2.insert(i2, ft::pair<std::string, int>("hello10", 10));
    
    for (ft::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << "i2 : " << i2->first << std::endl;

    std::cout << "map.erase(hello10) : " << map2.erase("hello10") << std::endl;
    std::cout << "map.erase(hello10) : " << map2.erase("hello10") << std::endl;
    
    map2.erase(++map2.begin());
    
    //std::cout << map2;
    //print(map2.getTree().getRoot());
}
    

int main()
{
    test_map();
    return (0);
}
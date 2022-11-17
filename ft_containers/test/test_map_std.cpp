/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_std.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:49:27 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/11/17 18:09:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map/map.h"
#include <string>
#include <map>
#include <ctime>

void test_map()
{
    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*          MAP             */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;


    std::time_t t0 = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&t0));

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*       BASICS FUNCT       */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    std::map<std::string, int> map;
    map.insert(std::pair<std::string, int>("hello1", 1));
    map.insert(std::pair<std::string, int>("hello1", 3));
    map.insert(std::pair<std::string, int>("hello3", 3));
    map.insert(std::pair<std::string, int>("hello4", 4));
    map.insert(std::pair<std::string, int>("hello2", 2));
    
    std::map<std::string, int> map2;

    {
        std::map<std::string, int> map3(map);
        map2 = map3;
    }

    std::cout << "\n\nmap begin() && end() : \n";
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "map 2 begin() && end() : \n";
    for (std::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::pair<const std::string, int> *pair = map2.get_allocator().allocate(1);
    map2.get_allocator().construct(pair, std::pair<std::string, int>("yo", 10));
    std::cout << "pair : " << pair->first << " / " << pair->second << std::endl;
    map2.get_allocator().destroy(pair);
    map2.get_allocator().deallocate(pair, 1);


    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*       ACCESS ELEMTS      */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
    std::cout << "\n\nAT" << std::endl;
    std::cout << "map.at(hello1) : " << map.at("hello1") << std::endl;
    const std::map<std::string, int> mapConst = map;
    std::cout << "mapConst.at(hello1) : " << mapConst.at("hello1");
    

    std::cout << "\n\n[]\n";
    std::cout << "map[hello3] : " << map["hello3"] <<  std::endl;
    std::cout << "map[hello10] : " << map["hello10"] <<  std::endl;
    map["yo"] = 10;
    std::cout << "map[yo] : " << map["yo"] <<  std::endl;

    std::cout << "\n\nprint map:\n";
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         CAPACITY         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    std::cout << "\n\nmap.size() : " << map.size() << std::endl;
    std::cout << "map.max_size() : " << map.max_size() << std::endl;
    std::cout << "map.empty() : " << map.empty() << std::endl;

    std::map<std::string, int> mapEmpty;
    std::cout << "\n\nmapEmpty.size() : " << mapEmpty.size() << std::endl;
    std::cout << "mapEmpty.max_size() : " << mapEmpty.max_size() << std::endl;
    std::cout << "mapEmpty.empty() : " << mapEmpty.empty() << "\n\n";

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*        ITERATORS         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
    std::cout  << "\n\ntest it:\n";
    std::map<std::string, int>::iterator it = map.begin();
    it--;
    it--;
 
    std::cout << "key: " << it->first;
    std::cout << " value: " << it->second;
    std::cout << std::endl;
    
    std::map<std::string, int>::reverse_iterator it2;
    it2 = map.rend();
    it2++;
    it2++;
    it2++;

    std::cout << "key: " << it->first;
    std::cout << " value: " << it->second;
    std::cout << std::endl << std::endl;

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
    for (std::map<std::string, int>::const_iterator it = mapConst.begin(); it != mapConst.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nCR_begin() && CR_end() : \n";
    for (std::map<std::string, int>::const_reverse_iterator it = mapConst.rbegin(); it != mapConst.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         LOOKUP           */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;


    if (map.find("hello1") != map.end())
        std::cout << "rslt find (hello1): " << map.find("hello1")->first;
    std::cout << "\ncount (hello3): " << map.count("hello3");
    
    if (map.find("not excist") != map.end())
        std::cout << "\nrslt find (not excist): " << map.find("not excist")->first;    
    std::cout << "\ncount (no excist): " << map.count("no excist");
    
    if (mapConst.find("hello1") != mapConst.end())
        std::cout << "\nrslt find (hello1): " << mapConst.find("hello1")->first;
    std::cout << "\ncount (hello3): " << mapConst.count("hello3");
    
    if (map.find("not excist") != map.end())
        std::cout << "\nrslt find (not excist): " << map.find("not excist")->first;    
    std::cout << "\ncount (no excist): " << map.count("no excist");
    
    std::cout << "\n\nequal_range" << std::endl;
    std::map<std::string, int> mapi;
    mapi.insert(map.begin(), map.end());
    std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> pr;
    pr = mapi.equal_range("hello3");
    std::cout << "pr->first: " << pr.first->first << std::endl;
    std::cout << "pr->second: " << pr.second->first << std::endl;
    

    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         MODIFIERS        */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
    std::cout << "\nmap 2 begin() && end() : \n";
    for (std::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << "\n\nclear map2\n";
    map2.clear();
    if (map2.empty())
        std::cout << "\n\nmap2 is empty()\n";

    std::cout << "\n\nmap 2 insert beg hello3\n";
    map2.insert(map.begin(), map.find("hello3"));
    for (std::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }

    std::cout << "\n\nmap 2 insert  pos = hello10 new value\n";
    map2.insert(map2.find("hello10"), std::pair<std::string, int>("hello101", 333));
    for (std::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }

    std::cout << "\n\nerase de hello101 a end\n";
    map2.erase(map2.find("hello101"), map2.end());
    for (std::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }


    std::cout << "\n\nmapSwap : \n\n";
    std::map<std::string, int> mapSwap;
    mapSwap.swap(map);
    for (std::map<std::string, int>::iterator it = mapSwap.begin(); it != mapSwap.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }

    if (map.empty())
        std::cout << "\n\nmap is empty()\n";
    
    std::cout << "\n\nswap again\n";
    map.swap(mapSwap);
    
    if (mapSwap.empty())
        std::cout << "\n\nmapSwap is empty()\n\n";
    
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    
    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*        OBSERVERS         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;

    std::map<std::string, int>::value_compare compV = map.value_comp();
    std::map<std::string, int>::key_compare compK = map.key_comp();
    std::cout << "\n\ncompKey: 123 / 234 : " <<  (compK("123", "234")) << std::endl;
    std::cout << "compKey: 123 / 123 : " <<  (compK("123", "123")) << std::endl;
    std::cout << "compKey: 123 / 12 : " <<  (compK("123", "12")) << std::endl;
    std::cout << "compValue: (hello3:3) / (hello4: 3) : " <<  (compV(std::pair<std::string, int>("hello3", 3), std::pair<std::string, int>("hello4", 3))) << std::endl;
    std::cout << "compValue: (hello3:3) / (hello2: 3) : " <<  (compV(std::pair<std::string, int>("hello3", 3), std::pair<std::string, int>("hello2", 3))) << std::endl;
    std::cout << "compValue: (hello8:8) / (hello8:8) : " <<  (compV(std::pair<std::string, int>("hello8", 8), std::pair<std::string, int>("hello8", 8))) << std::endl;
    std::cout << std::endl;
    
    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*        OPERATORS         */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    
    std::cout << "\n\noperators" << std::endl;
    std::map<std::string, int> m1;
    std::map<std::string, int> m2;
    m1.insert(std::pair<std::string, int>("hello1", 1));
    m1.insert(std::pair<std::string, int>("hello2", 2));
    m1.insert(std::pair<std::string, int>("hello3", 3));

    m2.insert(std::pair<std::string, int>("hello1", 1));
    m2.insert(std::pair<std::string, int>("hello2", 2));
    m2.insert(std::pair<std::string, int>("hello3", 4));
    //m2.insert(std::pair<std::string, int>("hello4", 4));

    std::cout << "== : " << (m1 == m2) <<  std::endl;
    std::cout << "!= : " << (m1 != m2) <<  std::endl;
    std::cout << "> : " << (m1 > m2) <<  std::endl;
    std::cout << ">= : " << (m1 >= m2) <<  std::endl;
    std::cout << "< : " << (m1 < m2) <<  std::endl;
    std::cout << "<= : " << (m1 <= m2) <<  std::endl;


    std::cout << "/*==========================*/" << std::endl;
    std::cout << "/*         perfo            */" << std::endl;
    std::cout << "/*==========================*/" << std::endl;
    std::time_t t1 = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&t1));    
    std::cout << "\n\nthe programme took: " << t1 - t0 << "ms\n";
}

/*void    test()
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

    std::map<std::string, int>::value_compare compV = map.value_comp();
    std::map<std::string, int>::key_compare compK = map.key_comp();
    std::cout << "compKey: " <<  (compK("123", "234")) << std::endl;
    std::cout << "compValue: " <<  (compV(std::pair<std::string, int>("hello3", 3), std::pair<std::string, int>("hello4", 4))) << std::endl;
    std::cout << "compValue: " <<  (compV(std::pair<std::string, int>("hello8", 8), std::pair<std::string, int>("hello4", 4))) << std::endl;


    std::cout << "equal_range" << std::endl;
    std::map<std::string, int> mapi;
    mapi.insert(map.begin(), map.end());
    std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> pr;
    pr = mapi.equal_range("hello3");
    std::cout << "pr->first: " << pr.first->first << std::endl;
    std::cout << "pr->second: " << pr.second->first << std::endl;

    std::cout << "\n\noperators" << std::endl;
    std::map<std::string, int> m1;
    std::map<std::string, int> m2;
    m1.insert(std::pair<std::string, int>("hello1", 1));
    m1.insert(std::pair<std::string, int>("hello2", 2));
    m1.insert(std::pair<std::string, int>("hello3", 3));

    m2.insert(std::pair<std::string, int>("hello1", 1));
    m2.insert(std::pair<std::string, int>("hello2", 2));
    m2.insert(std::pair<std::string, int>("hello3", 4));
    //m2.insert(std::pair<std::string, int>("hello4", 4));

    std::cout << "== : " << (m1 == m2) <<  std::endl;
    std::cout << "!= : " << (m1 != m2) <<  std::endl;
    std::cout << "> : " << (m1 > m2) <<  std::endl;
    std::cout << ">= : " << (m1 >= m2) <<  std::endl;
    std::cout << "< : " << (m1 < m2) <<  std::endl;
    std::cout << "<= : " << (m1 <= m2) <<  std::endl;
    
    std::cout << "==========================" << std::endl;
    std::cout << "         FT               " << std::endl;
    std::cout << "==========================" << std::endl;

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


    const ft::map<std::string, int>& cm = map2;
    std::cout << "\n\nC_begin() && C_rend() : \n";
    for (ft::map<std::string, int>::const_iterator it = cm.begin(); it != cm.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nCR_begin() && CR_end() : \n";
    for (ft::map<std::string, int>::const_reverse_iterator it = cm.rbegin(); it != cm.rend(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }
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
    for (ft::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "key: " << (*it).first;
        std::cout << " value: " << it->second;
        std::cout << std::endl;
    }


    std::cout << "equal_range" << std::endl;
    ft::map<std::string, int> mapi2;
    mapi2.insert(map2.begin(), map2.end());
    ft::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> pr2;
    pr2 = mapi2.equal_range("hello3");
    std::cout << "pr->first: " << pr2.first->first << std::endl;
    std::cout << "pr->second: " << pr2.second->first << std::endl;
    std::cout << map2;
   
   
    map2.erase(map2.begin(), map2.end());
    
    

    ft::map<std::string, int>::value_compare compV2 = map2.value_comp();
    ft::map<std::string, int>::key_compare compK2 = map2.key_comp();
    std::cout << "compKey: " <<  (compK2("123", "234")) << std::endl;
    std::cout << "compValue: " <<  (compV2(ft::pair<std::string, int>("hello3", 3), ft::pair<std::string, int>("hello4", 4))) << std::endl;
    std::cout << "compValue: " <<  (compV2(ft::pair<std::string, int>("hello8", 8), ft::pair<std::string, int>("hello4", 4))) << std::endl;
    //print(map2.getTree().getRoot());


    std::cout << "\n\noperators" << std::endl;
    ft::map<std::string, int> m3;
    ft::map<std::string, int> m4;
    m3.insert(ft::pair<std::string, int>("hello1", 1));
    m3.insert(ft::pair<std::string, int>("hello2", 2));
    m3.insert(ft::pair<std::string, int>("hello3", 3));

    m4.insert(ft::pair<std::string, int>("hello1", 1));
    m4.insert(ft::pair<std::string, int>("hello2", 2));
    m4.insert(ft::pair<std::string, int>("hello3", 4));
    //m4.insert(ft::pair<std::string, int>("hello4", 4));

    std::cout << "== : " << (m3 == m4) <<  std::endl;
    std::cout << "!= : " << (m3 != m4) <<  std::endl;
    std::cout << "> : " << (m3 > m4) <<  std::endl;
    std::cout << ">= : " << (m3 >= m4) <<  std::endl;
    std::cout << "< : " << (m3 < m4) <<  std::endl;
    std::cout << "<= : " << (m3 <= m4) <<  std::endl;


    
}*/
    

int main()
{
    test_map();
    return (0);
}
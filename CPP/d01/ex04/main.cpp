/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:25:41 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 16:32:34 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::ifstream   ifs(av[1]);
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string buf;
        std::string temp;
        
        if (ifs.fail())
        {
            std::cout << av[1] << " no such file or directory" << std::endl;
            return (0);
        }   
        std::ofstream   ofs(filename + ".replace");
        if (ofs.fail())
        {
            std::cout << "can't open " << filename + ".replace" << std::endl;
            return (0);
        }  
        while (getline(ifs, buf))
        {
            if (buf.find(s1) != std::string::npos)
            {
                while (buf.find(s1) != std::string::npos)
                {
                    //if (s2.compare("\\n") == 0)
                    //    ofs << buf.substr(0, buf.find(s1)) << std::endl;
                    //else
                        ofs << buf.substr(0, buf.find(s1)) << s2;
                    buf = buf.substr(buf.find(s1) + s1.size(), buf.size());
                }
                ofs << buf;
            }
            else
                ofs << buf;
            ofs << std::endl;
        }
        ifs.close();
        ofs.close();  
    }
    else
        std::cout << "Bad args" << std::endl;
    return (0);
}
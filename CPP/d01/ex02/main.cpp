/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:54:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/26 15:07:39 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPtr = &brain;
    std::string &stringRef = brain;

    std::cout << "memory add var: " << &brain << std::endl;
    std::cout << "memory add ptr: " << stringPtr << std::endl;
    std::cout << "memory add ref: " << &stringRef << std::endl << std::endl;
    
    std::cout << "value var: " << brain << std::endl;
    std::cout << "value ptr: " << *stringPtr << std::endl;
    std::cout << "value ref: " << stringRef << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:50:29 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/10/12 14:38:27 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/stack/Stack.hpp"
#include <vector>

void    test_stack()
{
    ft::stack<int> stack;

    std::cout << "stack:\n";
    std::cout << "size - empty\n";
    std::cout << stack.size() << " - " << stack.empty();
    std::cout << std::endl << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "push 1, 2, 3:\n";
    std::cout << "top - size - empty:\n";
    std::cout << stack.top() << " - " << stack.size() << " - " << stack.empty();
    std::cout << std::endl << std::endl;
    
    std::cout << "while(size) -> top -> pop:\n";
    size_t i = stack.size();
    while (i--)
    {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "size - empty\n";
    std::cout << stack.size() << " - " << stack.empty();
    std::cout << std::endl << std::endl;

    std::vector<int>    vec(10, 3);
    ft::stack<int, std::vector<int> >  stack2(vec);
    std::cout << "vec(10, 3); stack2(vec)\n";
    std::cout << "while(size) -> top -> pop:\n";
    i = stack2.size();
    while (i--)
    {
        std::cout << stack2.top();
        stack2.pop();
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    test_stack();
    return (0);
}
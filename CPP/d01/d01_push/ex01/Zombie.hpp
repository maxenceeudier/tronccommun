/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:52:07 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/13 09:41:04 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
    public:
        Zombie(std::string name);
        Zombie(void);
        ~Zombie(void);
    
        void    announce(void);
        void    setname(std::string name);
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, std::string name);


#endif
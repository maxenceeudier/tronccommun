/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:52:07 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/28 09:59:57 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie(void);
    
        void    announce(void);
    private:
        std::string _name;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif
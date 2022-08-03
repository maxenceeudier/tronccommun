/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:58:11 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/08/02 16:55:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &cpy);
        ~ClapTrap(void);

        ClapTrap    &operator=(ClapTrap const &clap2);

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        unsigned int    &getDamage(void);
        std::string     &getName(void);
        unsigned int    &getNrj(void);
        
    protected:
        std::string     _name;
        unsigned int    _hit;
        unsigned int    _nrj;
        unsigned int    _damage;
        ClapTrap(void);
          
};


#endif
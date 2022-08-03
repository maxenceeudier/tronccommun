/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:14:05 by meudier           #+#    #+#             */
/*   Updated: 2022/08/02 16:46:32 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TAP_HPP
#define DIAMOND_TAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class   DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
        DiamondTrap(void);
    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &cpy);
        ~DiamondTrap(void);

        DiamondTrap &operator=(DiamondTrap const &diamond2);
        void    whoAmI(void);
        void    attack(const std::string &target);
};

#endif
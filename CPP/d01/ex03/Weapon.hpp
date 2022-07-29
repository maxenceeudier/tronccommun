/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:21:11 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 12:43:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string> 

class Weapon
{
private:
    std::string _type;
    Weapon(void);
public:
    Weapon(std::string type);
    ~Weapon(void);
    
    const std::string   &getType(void);
    void                setType(std::string std);
};

#endif
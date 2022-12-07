/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:21:11 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/30 17:10:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string> 

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    Weapon(void);
    ~Weapon(void);
    
    const std::string   &getType(void);
    void                setType(std::string std);
};

#endif
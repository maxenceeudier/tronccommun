/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:43:06 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/29 11:56:08 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP 
# include <string>

enum type
{
    DEBUG_TYPE,
    INFO_TYPE,
    WARNING_TYPE,
    ERROR_TYPE
};

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warnig(void);
    void    error(void);
public:
    Harl();
    ~Harl();
    
    void    complain(std::string level);
};

#endif

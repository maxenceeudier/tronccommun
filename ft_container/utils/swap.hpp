/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:59 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/12/05 13:29:53 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

namespace ft
{
    template <class T>
	void swap (T & a, T & b)
	{
		T	tmp(a);
		a = b;
		b = tmp;
	}

	template <class T>
	void swap (T *a, T * b)
	{
		T	tmp(*a);
		*a = *b;
		*b = tmp;
	}
}

#endif
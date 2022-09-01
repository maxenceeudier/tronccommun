/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mid_and_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:53:46 by meudier           #+#    #+#             */
/*   Updated: 2022/05/17 16:26:26 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	get_len(int *temp, int mid, int size)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		if (temp[i] < mid)
			len++;
		i++;
	}
	return (len);
}

int	get_len_b(int *temp, int mid, int size)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		if (temp[i] > mid)
			len++;
		i++;
	}
	return (len);
}

int	get_mid_and_chunck(t_list *lst, int *mid, int *chunk)
{
	int	size;
	int	*temp;
	int	i;
	int	len;

	size = ft_lstsize(lst);
	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return (0);
	i = 0;
	while (lst)
	{
		temp[i] = lst->data;
		lst = lst->next;
		i++;
	}
	ft_sort(&temp, i);
	*mid = temp[size / 2];
	len = get_len(temp, *mid, size);
	*chunk += len;
	free(temp);
	return (1);
}

int	get_mid_and_chunck_b(t_list *lst, int *mid, int *chunk)
{
	int	size;
	int	*temp;
	int	i;
	int	len;

	size = ft_lstsize(lst);
	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return (0);
	i = 0;
	while (lst)
	{
		temp[i] = lst->data;
		lst = lst->next;
		i++;
	}
	ft_sort(&temp, i);
	*mid = temp[size / 2];
	len = get_len_b(temp, *mid, size);
	*chunk += len;
	free(temp);
	return (1);
}

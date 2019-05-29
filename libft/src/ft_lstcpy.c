/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:23:46 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/13 17:24:25 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list	*new_list;
	t_list	*new_head;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	new_head = ft_lstnew(lst->content, lst->content_size);
	new_list = new_head;
	ptr = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(lst->content, lst->content_size);
		lst = lst->next;
	}
	new_list->next = NULL;
	return (ptr);
}

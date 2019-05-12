/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:38:06 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/14 18:56:09 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *ptr;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	ptr = list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(list->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	return (ptr);
}

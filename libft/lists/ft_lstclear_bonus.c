/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 06:26:10 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 12:11:01 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del(void *element)
{
	element = NULL;
	free(element);
} */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*temp;

	list = (*lst);
	while (list)
	{
		temp = list->next;
		ft_lstdelone(list, del);
		list = temp;
	}
	(*lst) = NULL;
}

/* int main()
{
	t_list	*list;

	list = ft_lstnew("test");
	ft_lstadd_front(&list, ft_lstnew("albillie"));
	ft_lstadd_front(&list, ft_lstnew("damdam"));
	ft_lstadd_front(&list, ft_lstnew("anoteris"));
	ft_lstadd_front(&list, ft_lstnew("gbsruscan"));

	ft_lstclear(&list, del);

	// printf("%s\n", (char *) list->content);
} */

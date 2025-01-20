/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:42:04 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 09:18:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del(void *element)
{
	element = NULL;
	free(element);
} */

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	del(lst->content);
	free(lst);
}

/* int main()
{
	t_list *list;

	list = ft_lstnew("kaveO");
	ft_lstadd_front(&list, ft_lstnew("albillie"));
	// ft_lstadd_front(&list, ft_lstnew("gbruscan"));
	// ft_lstadd_front(&list, ft_lstnew("j'adore les chats"));


	ft_lstdelone(list, del);
	// list = list->next;
	printf("%s\n", (char *) list->next);
	// ft_lstdelone(list, del);
} */

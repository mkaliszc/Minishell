/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:59:34 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 11:59:58 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = (*lst);
	if (!ptr)
		(*lst) = new;
	else
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
	}
}

/* int main()
{
	t_list *list;

	list = ft_lstnew("j'adore les chats !");
	ft_lstadd_back(&list, ft_lstnew("test"));
	ft_lstadd_back(&list, ft_lstnew("gbruscan"));
	t_list *ptr;

	ptr = list;
	while (ptr->next)
	{
		printf("%s\n", (char *) ptr->content);
		ptr = ptr->next;
	}
	printf("%s\n", (char *) ptr->content);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:18:59 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 11:57:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int main()
{
	t_list *list;
	list = ft_lstnew("hgduyk");
	ft_lstadd_front(&list, ft_lstnew("lenovo"));
	ft_lstadd_front(&list, ft_lstnew("chats"));
	ft_lstadd_front(&list, ft_lstnew("musique"));
	t_list *current = list;
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:32 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 11:59:02 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	test_function(void *data)
{
	printf("%s\n", (char *) data);
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/* int main()
{
	t_list *list;

	list = ft_lstnew("test");
	ft_lstadd_back(&list, ft_lstnew("albillie"));
	ft_lstadd_back(&list, ft_lstnew("anoteris"));
	ft_lstadd_back(&list, ft_lstnew("damian"));

	ft_lstiter(list, test_function);
} */

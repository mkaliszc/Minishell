/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:34:12 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 11:57:58 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

// int main()
// {
// 	t_list *list;

// 	list = ft_lstnew("test");
// 	ft_lstadd_front(&list, ft_lstnew("anoteris"));
// 	ft_lstadd_front(&list, ft_lstnew("gbruscam"));
// 	ft_lstadd_front(&list, ft_lstnew("ax-burin"));

// 	printf("%s\n", (char *) ft_lstlast(list));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:00:09 by albillie          #+#    #+#             */
/*   Updated: 2024/12/16 11:57:50 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// int main()
// {
// 	t_list *list;

// 	list = ft_lstnew("anoteris");
// 	ft_lstadd_front(&list, ft_lstnew("gbruscan"));
// 	ft_lstadd_front(&list, ft_lstnew("gbruscan"));
// 	ft_lstadd_front(&list, ft_lstnew("test"));
// 	// t_list *current;
// 	// current = list;

// 	printf("%d\n", ft_lstsize(list));
// }

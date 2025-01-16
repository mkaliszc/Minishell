/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:04:18 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 06:06:00 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}


int main(int ac, char **av, char **envp)
{
	t_env *env;
	(void)ac;
	(void)av;
	char *line;
	env = create_lst_env(envp);
	while (true)
	{
		line = readline(GREEN"WildShell $ "END);
		char **command = ft_split(line, ' ');
		if (ft_strcmp(command[0], "pwd") == 0)
		{
			handle_pwd();
		}
		else if (ft_strcmp(command[0], "cd") == 0)
		{
			handle_cd(command);
			update_env_paths(env);
			show_one_lst_env(env, "PWD");
		}
		else if (ft_strcmp(command[0], "env") == 0)
		{
			show_all_lst_env(env);
		}
		else if (ft_strcmp(command[0], "echo") == 0)
		{
			handle_echo(command);
		}
		else if (ft_strcmp(command[0], "exit") == 0)
		{
			break; // ! Have to work on exit command right here.
		}
		else if (ft_strcmp(command[0], "export") == 0)
		{
			handle_export(command[1], env);
		}
	}
}

// // ? Functions for env variables list

// t_env	*init_env_struct(char **envp)
// {
// 	t_env	*env;

// 	env = malloc(sizeof(t_env));
// 	if (!env)
// 		return (NULL);
// 	env->env = envp[0];
// 	env->next = NULL;
// 	int i = 1;
// 	while (envp[i])
// 	{
// 		env_add_back(&env, env_lst_new(envp[i]));
// 		i++;
// 	}
// 	return (env);
// }
// t_env	*env_lst_new(char *data)
// {
// 	t_env	*env;

// 	env = malloc(sizeof(t_env));
// 	if (!env)
// 		return (NULL);
// 	env->env = data;
// 	env->next = NULL;
// 	return (env);
// }

// void	env_add_back(t_env **env, t_env *new)
// {
// 	t_env	*ptr;

// 	if (!env)
// 		return ;
// 	ptr = (*env);
// 	if (!ptr)
// 		(*env) = new;
// 	else
// 	{
// 		while (ptr->next)
// 		{
// 			ptr = ptr->next;
// 		}
// 		ptr->next = new;
// 	}
// }

// void	print_env_list(t_env *env)
// {
// 	while (env)
// 	{
// 		ft_printf("%s\n", env->env);
// 		env = env->next;
// 	}
// }


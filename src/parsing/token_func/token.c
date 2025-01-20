/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:09:09 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/20 02:42:35 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	nb_of_cmd(char *ln_cmd)
{
	int i;
	int	count;

	i = 0;
	count = 1;
	while (ln_cmd[i])
	{
		if (ln_cmd[i] == '"')
			while_d_quote(ln_cmd, &i);
		if (ln_cmd[i] == '\'')
			while_s_quote(ln_cmd, &i);
		if (ln_cmd[i] == '|')
			count++;
		++i;
	}
	return (count);
}

void	show_split(char **c_split)
{
	int	i;

	i = 0;
	while (c_split[i])
	{
		printf("split cmd : /%s/\n", c_split[i]);
		++i;
	}
}

void	free_split(char **c_split)
{
	int	i;

	i = 0;
	while (c_split[i])
	{
		free(c_split[i]);
		++i;
	}
	free(c_split);
}

void	nb_of_redir(char **split_cmd)
{
	int	i;
	int	j;
	int count;

	i = 0;
	while (split_cmd[i])
	{
		j = 0;
		count = 0;
		while (split_cmd[i][j])
		{
			if (split_cmd[i][j] == '"')
				while_d_quote(split_cmd[i], &j);
			if (split_cmd[i][j] == '\'')
				while_s_quote(split_cmd[i], &j);
			if (split_cmd[i][j] == '<' || split_cmd[i][j] == '>')
			{
				++count;
				while(split_cmd[i][j] == '<' || split_cmd[i][j] == '>')
					++j;
				while (split_cmd[i][j] == ' ' && split_cmd[i][j])
					++j;
			}
			else
				++j;
		}
		printf("nb of redir : %d\n", count);
		++i;
	}
}

void	tp_n_file_redir(char **split_cmd)
{
	int	i;
	int	j;
	int start;
	int end;

	i = 0;
	while (split_cmd[i])
	{
		j = 0;
		while (split_cmd[i][j])
		{
			if (split_cmd[i][j] == '"')
				while_d_quote(split_cmd[i], &j);
			else if (split_cmd[i][j] == '\'')
				while_s_quote(split_cmd[i], &j);
			else if (split_cmd[i][j] == '<')
			{
				++j;
				if (split_cmd[i][j] == '<')
				{
					++j;
					while(split_cmd[i][j] == ' ')
						++j;
					start = j;
					while(split_cmd[i][j] != ' ' && split_cmd[i][j])
					{
						if(split_cmd[i][j] == '"')
							while_d_quote(split_cmd[i], &j);
						else if (split_cmd[i][j] == '\'')
							while_s_quote(split_cmd[i], &j);
						else
					 		++j;
					}
					end = j;
					printf(" redir << : %s|\n", ft_substr(split_cmd[i], start, end - start));
				}
				else
				{
					while(split_cmd[i][j] == ' ')
						++j;
					start = j;
					while(split_cmd[i][j] != ' ' && split_cmd[i][j])
					{
						if(split_cmd[i][j] == '"')
							while_d_quote(split_cmd[i], &j);
						else if (split_cmd[i][j] == '\'')
							while_s_quote(split_cmd[i], &j);
						else
							++j;
					}
					end = j;
					printf(" redir < : %s|\n", ft_substr(split_cmd[i], start, end - start));
				}
			}
			else if (split_cmd[i][j] == '>')
			{
				j++;
				if (split_cmd[i][j] == '>')
				{
					++j;
					while(split_cmd[i][j] == ' ')
						++j;
					start = j;
					while(split_cmd[i][j] != ' ' && split_cmd[i][j])
					{
						if(split_cmd[i][j] == '"')
							while_d_quote(split_cmd[i], &j);
						else if (split_cmd[i][j] == '\'')
							while_s_quote(split_cmd[i], &j);
						else
					 		++j;
					}
					end = j;
					printf(" redir >> : %s|\n", ft_substr(split_cmd[i], start, end - start));
				}
				else
				{
					while(split_cmd[i][j] == ' ')
					++j;
					start = j;
					while(split_cmd[i][j] != ' ' && split_cmd[i][j])
					{
						if(split_cmd[i][j] == '"')
							while_d_quote(split_cmd[i], &j);
						else if (split_cmd[i][j] == '\'')
							while_s_quote(split_cmd[i], &j);
						else
							++j;
					}
					end = j;
					printf(" redir >> : %s|\n", ft_substr(split_cmd[i], start, end - start));
				}
			}
			else
				++j;
		}
	++i;
	}
}

char	**split_cmd(char *ln_cmd)
{
	char **split_cmd;
	int		i;
	int		start;
	int		end;

	split_cmd = malloc(sizeof(char *) * (nb_of_cmd(ln_cmd) + 1));
	end = 0;
	start = 0;
	i = 0;
	while (ln_cmd[end])
	{
		if(ln_cmd[end] == '"')
			while_d_quote(ln_cmd, &end);
		if(ln_cmd[end] == '\'')
			while_s_quote(ln_cmd, &end);
		if(ln_cmd[end] == '|')
		{
			split_cmd[i++] = ft_substr(ln_cmd, start, end - start);
			start = end + 1;
		}
		if (!ln_cmd[end + 1])
			split_cmd[i++] = ft_substr(ln_cmd, start, end + 1 - start);
		++end;
	}
	split_cmd[i] = NULL;
	return (split_cmd);
}

void	while_a_brckt(char *cmd, int *i)
{
	while((cmd[*i] == '<' || cmd[*i] == '>') && cmd [*i])
		++*i;
	while(cmd[*i] == ' ' && cmd[*i])
		++*i;
	while (cmd[*i] && cmd[*i] != ' ')
	{
		if (cmd[*i] == '"')
			while_d_quote(cmd, i);
		else if (cmd[*i] == '\'')
			while_s_quote(cmd, i);
		else
			++*i;
	}
}

void	list_cmd_n_arg(char **cmd_split)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	while (cmd_split[i])
	{
		j = 0;
		while(cmd_split[i][j])
		{
			if (cmd_split[i][j] == ' ')
				++j;
			else if (cmd_split[i][j] == '<' || cmd_split[i][j] == '>')
				while_a_brckt(cmd_split[i], &j);
			else
			{
				start = j;
				while(cmd_split[i][j] && (cmd_split[i][j] != ' ' && cmd_split[i][j] != '<' && cmd_split[i][j] != '>'))
				{
					if (cmd_split[i][j] == '"')
						while_d_quote(cmd_split[i], &j);
					else if (cmd_split[i][j] == '\'')
						while_s_quote(cmd_split[i], &j);
					++j;
				}
				end = j;
				printf("arg : |%s|\n", ft_substr(cmd_split[i], start, end - start));
			}
		}
		++i;
	}
}
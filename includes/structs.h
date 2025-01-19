/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 03:58:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/19 05:10:05 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum	s_tokens t_tokens;
typedef enum	s_rd_file t_rd_file;
typedef struct	s_env t_env;
typedef struct	s_order_file t_order_file;
/*
* struct s_lst_cmd | list all cmd in chain with her argument,
* all hdc, order of infile/hdc,order of out/appd and if this cmd or builtins
* char **cmd | table of cmd with her flags
* bool is_builtins | true = builtins / false = cmd
* t_hdc | see ref struct s_hdc
* t_order_in | see ref struct s_order_in
* t_order_out | see red struct t_order_out
*/
typedef struct	s_lst_cmd t_list_cmd;
/*
* struct s_mini | give env variable nb of cmd and list of cmd
* int nb_cmd | give nb of cmd
* t_env | see ref struct s_env
* t_lst_cmd | see ref struct s_lst_cmd
*/
typedef struct	s_mini t_mini;
typedef struct	s_data t_data;

#endif

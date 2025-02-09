/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 03:58:44 by albillie          #+#    #+#             */
/*   Updated: 2025/01/24 04:15:35 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
Enum struct used to identify tokens
*/
typedef enum s_tokens			t_tokens;
typedef enum s_rd_file			t_rd_file;
/*
Linked list of all env variables
key -> data before '=' int the list
value -> data after '=' in the list
*/
typedef struct s_env			t_env;
typedef struct s_order_file		t_order_file;
/*
* struct s_lst_cmd | list all cmd in chain with her argument,
* all hdc, order of infile/hdc,order of out/appd and if this cmd or builtins
* char **cmd | table of cmd with her flags
* bool is_builtins | true = builtins / false = cmd
* t_hdc | see ref struct s_hdc
* t_order_in | see ref struct s_order_in
* t_order_out | see red struct t_order_out
*/
typedef struct s_lst_cmd		t_lst_cmd;
/*
* struct s_mini | give env variable nb of cmd and list of cmd
* int nb_cmd | give nb of cmd
* t_env | see ref struct s_env
* t_lst_cmd | see ref struct s_lst_cmd
*/
typedef struct s_mini			t_mini;
typedef struct s_data			t_data;
typedef struct s_pain			t_pain;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:27:10 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:27:10 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSING_H
# define STRUCT_PARSING_H

typedef struct				s_vertices
{
	int						x;
	int						y;
	char					*name;
	struct s_vertices		*next;
}							t_vertices;

typedef struct				s_edges
{
	char					*from;
	char					*to;
	struct s_edges			*next;
}							t_edges;

typedef struct				s_data
{
	int						ants;
	int						set_source;
	int						set_sink;
	int						set_vertices;
	char					*source;
	char					*sink;
	int						flag;
	t_vertices				*vertices;
	t_edges					*edges;
}							t_data;

#endif

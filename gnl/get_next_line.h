/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 12:37:05 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/01/24 12:39:25 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 1000
# define MAX_SIZE_FD 2560

int					get_next_line(const int fd, char **line);

typedef struct		s_l
{
	char			*tmp;
	char			*s[1042];
	int				nl[1042];
}					t_l;

#endif

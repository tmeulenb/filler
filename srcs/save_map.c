#include "../filler.h"

void			initialize_input_and_map(t_map *m)
{
	int			i;

	i = 0;
	m->input = (char **)malloc(sizeof(char *) * m->rows + 1);
	m->map = (int **)malloc(sizeof(int *) * m->rows);
	while (i < m->rows)
	{
		m->input[i] = (char *)malloc(sizeof(char) * m->cols + 1);
		m->map[i] = (int *)malloc(sizeof(int) * m->cols);
		i++;
	}
	m->input[i] = NULL;
	return ;
}

void			copy_line(t_map *m, char *line, int i)
{
	int		j;

	j = 0;
	while (line[j + 4])
	{
		m->input[i][j] = line[j + 4];
		if (line[j + 4] == '.')
			m->map[i][j] = 0;
		if (line[j + 4] == 'O')
			m->map[i][j] = -1;
		if (line[j + 4] == 'X')
			m->map[i][j] = -2;
		if (line[j + 4] == m->enemy_XO)
			m->map[i][j] = -3;
		j++;
	}
	m->input[i][j] = '\0';
	return ;
}

void			get_map(t_map *m)
{
	int			i;
	char		*line;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	if (!m->input && !m->map)
		initialize_input_and_map(m);
	while (i < m->rows)
	{
		get_next_line(0, &line);
		copy_line(m, line, i);
		i++;
		ft_strdel(&line);
	}
	return ;
}

void			get_map_size(char *line, t_map *m)
{
	char		**split;
	
	if (m->rows == 0 && m->cols == 0)
	{
		split = ft_strsplit(line, ' ');
		if (!split)
			error();
		m->rows = ft_atoi(split[1]);
		m->cols = ft_atoi(split[2]);
		free_str_array(split);
	}
	get_map(m);
}

int				get_input(t_map *m)
{
	char		*line;
	int			ret;

	line = NULL;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == 0)
			break ;
		if (ret == -1)
			error();
		if (ft_strncmp(line, "Plateau ", 8) == 0)
		{
			get_map_size(line, m);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece ", 6) == 0)
		{
			get_piece_size(line, m->piece, m);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

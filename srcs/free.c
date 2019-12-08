#include "../filler.h"

void		free_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return ;
}

void		free_piece(t_piece *p)
{
	int			i;

	i = 0;
	while (i < p->rows)
	{
		free(p->piece[i]);
		i++;
	}
	free(p->piece);
	i = 0;
	while (i < p->cut_rows)
	{
		free(p->cut_piece[i]);
		i++;
	}
	free(p->cut_piece);
	free(p);
}

void		free_input_and_map(t_map *m)
{
	int			i;

	i = 0;
	while (i < m->rows)
	{
		free(m->input[i]);
		free(m->map[i]);
		i++;
	}
	free(m->input);
	free(m->map);
	return ;
}

void		free_all(t_map *m)
{
	free_piece(m->piece);
	free_queue(m, m->q);
	free_input_and_map(m);
	free(m);
}

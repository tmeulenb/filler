#include "../filler.h"

void		free_queue(t_map *m, t_pos **q)
{
	int			i;

	i = 0;
	while (i < (m->cols * m->rows))
	{
		free(q[i]);
		i++;
	}
	free(q);
	return ;
}

void		initialize_or_reset_queue(t_map *m)
{
	int			i;
	int			n;

	i = 0;
	n = m->cols * m->rows;
	m->q_n = 0;
	if (!m->q)
		m->q = malloc(sizeof(t_pos *) * n);
	m->q[n] = NULL;
	while (i < n)
	{
		if (!m->q[i])
			m->q[i] = malloc(sizeof(t_pos));
		m->q[i]->x = 0;
		m->q[i]->y = 0;
		i++;
	}
	return ;
}

void		add_to_queue(t_map *m, int y, int x, int level)
{
	if (level == -3 && m->map[y][x] >= 0)
		m->map[y][x] = 1;
	if (level == m->enemy_id && m->map[y][x] >= 0)
		m->map[y][x] = 10;
	else if (level >= 0)
		m->map[y][x] = level + 1;
	if (m->map[y][x] >= 0)
	{
		m->q[m->q_n]->x = x;
		m->q[m->q_n]->y = y;
		m->q_n += 1;
	}
	return ;
}

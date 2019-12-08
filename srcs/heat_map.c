#include "../filler.h"

int			check_boundaries(t_map *m, int y, int x)
{
	if (y >= m->rows || y < 0)
		return (0);
	if (x >= m->cols || x < 0)
		return (0);
	return (1);
}

void		level_all_surrounding(t_map *m, int	y, int x, int level)
{
	if (check_boundaries(m, y, x + 1) && m->map[y][x + 1] == 0)
		add_to_queue(m , y, x + 1, level);
	if (check_boundaries(m, y, x - 1) && m->map[y][x - 1] == 0)
		add_to_queue(m , y, x - 1, level);
	if (check_boundaries(m, y + 1, x) && m->map[y + 1][x] == 0)
		add_to_queue(m , y + 1, x, level);
	if (check_boundaries(m, y - 1, x) && m->map[y - 1][x] == 0)
		add_to_queue(m , y - 1, x, level);
	if (check_boundaries(m, y + 1, x + 1) && m->map[y + 1][x + 1] == 0)
		add_to_queue(m , y + 1, x + 1, level);
	if (check_boundaries(m, y - 1, x - 1) && m->map[y - 1][x - 1] == 0)
		add_to_queue(m , y - 1, x - 1, level);
	if (check_boundaries(m, y - 1, x + 1) && m->map[y - 1][x + 1] == 0)
		add_to_queue(m , y - 1, x + 1, level);
	if (check_boundaries(m, y + 1, x - 1) && m->map[y + 1][x - 1] == 0)
		add_to_queue(m , y + 1, x - 1, level);
	return ;
}
	
void		level_from_enemy_piece(t_map *m)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	while (i < m->q_n)
	{
		y = m->q[i]->y;
		x = m->q[i]->x;
		level_all_surrounding(m, y, x, m->map[y][x]);
		i++;
	}
	return ;
}

void		make_heat_map(t_map *m)
{
	int			y;
	int			x;
	
	y = 0;
	while (y < m->rows)
	{
		x = 0;
		while (x < m->cols)
		{
			if (m->map[y][x] == -3 || m->map[y][x] == m->enemy_id)
				level_all_surrounding(m, y, x, m->map[y][x]);
			x++;
		}
		y++;
	}
	level_from_enemy_piece(m);
	return ;
}

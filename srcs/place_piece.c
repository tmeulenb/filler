#include "../filler.h"

int			check_boundaries_of_piece(t_map *m, int y, int x)
{
	if ((x + m->piece->cut_cols) > m->cols)
		return (0);
	if ((y + m->piece->cut_rows) > m->rows)
		return (0);
	return (1);
}

int			check_for_overlap(t_map *m, int y, int x)
{
	int			overlap;
	int			i;
	int			j;

	overlap = 0;
	j = 0;
	if (!check_boundaries_of_piece(m, y, x))
		return (1);
	while (j < m->piece->cut_rows)
	{
		i = 0;
		while (i < m->piece->cut_cols)
		{
			if (m->map[y + j][x + i] == m->XO_id && m->piece->cut_piece[j][i] == '*')
				overlap++;
			if (m->map[y + j][x + i] == m->enemy_id && m->piece->cut_piece[j][i] == '*')
				return (1);
			i++;
		}
		j++;
	}
	if (overlap != 1)
		return (1);
	return (0);
}

int			calculate_placement_score(t_map *m, int y, int x)
{
	int			score;
	int			i;
	int			j;

	score = 0;
	j = 0;
	while (j < m->piece->cut_rows)
	{
		i = 0;
		while (i < m->piece->cut_cols)
		{
			if (m->map[y + j][x + i] != m->XO_id && m->map[y + j][x + i] != 0)
				score += m->map[y + j][x + i];
			i++;
		}
		j++;
	}
	if (score == 0)
		return (1000);
	return (score);
}

void		check_piece(t_map *m, int y, int x)
{
	int			score;

	score = 0;
	if (check_for_overlap(m, y, x))
		return ;
	score = calculate_placement_score(m, y, x);
	if (score < m->piece->placement_score)
	{
		m->piece->placement_score = score;
		m->piece->placement_x = x;
		m->piece->placement_y = y;
	}
	return ;
}

void		place_piece(t_map *m)
{
	int			y;
	int			x;

	y = 0;
	while (y < m->rows)
	{
		x = 0;
		while (x < m->cols)
		{
			check_piece(m, y, x);
			x++;
		}
		y++;
	}
	return ;
}

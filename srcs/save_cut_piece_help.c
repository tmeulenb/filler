#include "../filler.h"

void			find_amount_used_cols(t_piece *p)
{
	int		x;
	int		y;
	int		ret;

	x = 0;
	while (x < p->cols)
	{
		y = 0;
		ret = 0;
		while (y < p->rows)
		{
			if (p->piece[y][x] == '*')
				ret = 1;
			y++;
		}
		if (ret == 1)
			p->cut_cols += 1;
		x++;
	}
	return ;
}

void			find_amount_used_rows(t_piece *p)
{
	int		x;
	int		y;
	int		ret;

	y = 0;
	while (y < p->rows)
	{
		x = 0;
		ret = 0;
		while (x < p->cols)
		{
			if (p->piece[y][x] == '*')
				ret = 1;
			x++;
		}
		if (ret == 1)
			p->cut_rows += 1;
		y++;
	}
	return ;
}

int				find_starting_y(t_piece *p)
{
	int		x;
	int		y;

	y = 0;
	while (y < p->rows)
	{
		x = 0;
		while (x < p->cols)
		{
			if (p->piece[y][x] == '*')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

int				find_starting_x(t_piece *p)
{
	int		x;
	int		y;

	x = 0;
	while (x < p->cols)
	{
		y = 0;
		while (y < p->rows)
		{
			if (p->piece[y][x] == '*')
				return (x);
			y++;
		}
		x++;
	}
	return (-1);
}

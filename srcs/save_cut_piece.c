#include "../filler.h"

void			initialize_cut_piece(t_piece *p)
{
	int			i;
	
	i = 0;
	p->cut_piece = malloc(sizeof(char *) * p->cut_rows + 1);
	p->cut_piece[p->cut_rows] = NULL;
	while (i < p->cut_rows)
	{
		p->cut_piece[i] = malloc(sizeof(char) * p->cut_cols + 1);
		p->cut_piece[i][p->cut_cols] = 0;
		i++;
	}
	return ;
}
	
void			save_cut_piece(t_piece *p)
{
	int			y;
	int			x;

	p->offset_y = find_starting_y(p);
	p->offset_x = find_starting_x(p);
	y = 0;
	while (y < p->cut_rows)
	{
		x = 0;
		while (x < p->cut_cols)
		{
			p->cut_piece[y][x] = p->piece[y + p->offset_y][x + p->offset_x];
			x++;
		}
		y++;
	}
	return ;
}

t_piece 		*cut_piece(t_piece *p)
{
	p->cut_cols = 0;
	p->cut_rows = 0;
	find_amount_used_cols(p);
	find_amount_used_rows(p);
	initialize_cut_piece(p);
	save_cut_piece(p);
	return (p);
}

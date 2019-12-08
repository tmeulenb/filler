#include "../filler.h"

void        error(void)
{
    write(1, "ERROR\n", 6);
	exit (1);
    return ;
}

t_map       *initialize_map(void)
{
    t_map       *m;
	int			i;

	i = 0;
    m = malloc(sizeof(t_map));
	m->input = NULL;
	m->q_n = 0;
	m->q = NULL;
	m->map = NULL;
	m->piece = NULL;
	m->player = 0;
    m->rows = 0;
    m->cols = 0;
	m->close = 0;
	m->XO = '.';
	m->XO_id = 0;
	m->enemy_XO = '.';
	m->enemy_id = 0;
    return (m);
}

void		get_player(t_map *m)
{
	char		*line;

	if (get_next_line(0, &line) == -1)
		error();
	if (ft_strncmp(line, "$$$", 3) == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			m->enemy_XO = 'o';
			m->enemy_id = -1;
			m->XO = 'x';
			m->XO_id = -2;
		}
		if (ft_strstr(line, "p1"))
		{
			m->enemy_XO = 'x';
			m->enemy_id = -2;
			m->XO = 'o';
			m->XO_id = -1;
		}
	}
	ft_strdel(&line);
}

void		output_coordinates(t_map *m)
{
	ft_putnbr(m->piece->placement_y - m->piece->offset_y);
	ft_putchar(' ');
	ft_putnbr(m->piece->placement_x - m->piece->offset_x);
	ft_putchar('\n');
	return ;
}

int         main()
{
    t_map		*m;

	m = initialize_map();
	get_player(m);
	while (1)
	{
		if (!get_input(m))
			error();
		initialize_or_reset_queue(m);
		make_heat_map(m);
		place_piece(m);
		if (m->piece->placement_score == INT32_MAX)
		{
			output_coordinates(m);
			break ;
		}
		output_coordinates(m);
		free_piece(m->piece);
	}
	free_all(m);
    return (1);
}

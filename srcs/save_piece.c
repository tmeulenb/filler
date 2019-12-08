#include "../filler.h"

void		get_piece(t_piece *p, t_map *m)
{
	int		i;
	char	*line;

	i = 0;
	p->piece = (char **)malloc(sizeof(char *) * (p->rows + 1));
	while (i < p->rows)
	{
		get_next_line(0, &line);
		p->piece[i] = (char *)malloc(sizeof(char *) * (p->cols + 1));
		p->piece[i] = ft_strcpy(p->piece[i], (const char *)line);
		i++;
		ft_strdel(&line);
	}
	m->piece = cut_piece(p);
}

void		get_piece_size(char *line, t_piece *p, t_map *m)
{
	char			**split;

	p = malloc(sizeof(t_piece));
	p->piece = NULL;
	split = ft_strsplit(line, ' ');
	if (!split)
		error();
	p->rows = ft_atoi(split[1]);
    p->cols = ft_atoi(split[2]);
	p->offset_x = 0;
	p->offset_y = 0;
	p->placement_x = 0;
	p->placement_y = 0;
	p->placement_score = INT32_MAX;
	ft_strdel(&line);
	free_str_array(split);
	get_piece(p, m);
}

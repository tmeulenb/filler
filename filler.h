# ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

# define PLAYERNAME "tmeulenb"

# define oO(x) x == 'o' || x == 'O'
# define xX(x) x == 'x' || x == 'X'

typedef struct          s_piece
{
    char                **piece;
    int                 rows;
    int                 cols;
	char				**cut_piece;
	int					cut_rows;
	int					cut_cols;
	int					offset_x;
	int					offset_y;
	int					placement_x;
	int					placement_y;
	int					placement_score;
}                       t_piece;

typedef struct          s_pos
{
    int					x;
	int					y;
}                       t_pos;

typedef struct          s_map
{
    char                **input;
	int					n_input;
	int					**map;
	t_piece				*piece;
	t_pos				**q;
	int					q_n;
    int                 rows;
    int                 cols;
	int					player;
	int					close;
    char                XO;
	int					XO_id;
	char				enemy_XO;
	int					enemy_id;
}                       t_map;

void        			error(void);

void					free_str_array(char **str);
void					free_piece(t_piece *p);
void					free_all(t_map *m);

t_map       			*initialize_map(void);
void					save_map_and_piece(t_map *m);
void					save_map_variables(t_map *m);

void					initialize_playing_map(t_map *m);

void					get_piece_size(char *line, t_piece *p, t_map *m);

t_piece					*cut_piece(t_piece *p);

/*
**	save_map.c
*/
int						get_input(t_map *m);

/*
**	save_cut_piece_help.c
*/
void					find_amount_used_cols(t_piece *p);
void					find_amount_used_rows(t_piece *p);
int						find_starting_y(t_piece *p);
int						find_starting_x(t_piece *p);

/*
**	place_piece.c
*/
void					place_piece(t_map *m);

/*
**	heat_map.c
*/
void					add_to_queue(t_map *m, int y, int x, int level);
void					make_heat_map(t_map *m);

/*
**	queue.c
*/
void					free_queue(t_map *m, t_pos **q);
void					initialize_or_reset_queue(t_map *m);
void					add_to_queue(t_map *m, int y, int x, int level);

#endif
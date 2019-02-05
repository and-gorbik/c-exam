#ifndef FIGURE_H
#define FIGURE_H

typedef struct		s_figure {
	char			type;
	int				i;
	int				j;
	struct s_figure	*next;
}					t_figure;

void            	free_figures(t_figure **lst);
t_figure			*new_figure(char type, int i, int j);
t_figure			*add_figure(t_figure *first, char type, int i, int j);

#endif
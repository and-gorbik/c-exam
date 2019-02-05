#include "check_mate.h"

static void		parse_args(t_figure **king, t_figure **figures, int argc, char **argv)
{
	for (int i = 0; i < argc; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			if (argv[i][j] == 'Q' || argv[i][j] == 'B' || argv[i][j] == 'R' || argv[i][j] == 'P')
				*figures = add_figure(*figures, argv[i][j], i, j);
			if (argv[i][j] == 'K')
			    king = new_figure(argv[i][j], i, j);
		}
	}
}

static int     is_found(t_figure *king, t_figure *cur)
{
    int flag;

    if (!king || !cur)
        return (-1);
    flag = 0;
	while (cur && !flag)
	{
        switch (cur->type)
        {
            case 'P':
                flag = check_mate_from_pawn(king, cur);
                break;
            case 'B':
                flag = check_mate_from_bishop(king, cur);
                break;
            case 'R':
                flag = check_mate_from_rook(king, cur);
                break;
            case 'Q':
                flag = check_mate_from_queen(king, cur);
                break;
        }
        cur = cur->next;
    }
    return (flag);   
} 

int				main(int argc, char **argv)
{
	t_figure	*lst;
	t_figure	*king;

	if (argc > 1)
	{
		lst = NULL;
		parse_args(&king, &lst, argc, argv);
		if (!lst || !king)
        {
            write(1, "Fail\n", 5);
            lst ? free_figures(&lst) : free_figures(&king);
			return (0);
        }
		is_found(king, lst) ? write(1, "Success", 7) : write(1, "Fail", 4);
		free_figures(&lst);
        free_figures(&king);
	}
	write(1, "\n", 1);
	return (0);
}
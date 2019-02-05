#include "check_mate.h"

int				check_mate_from_bishop(t_figure *king, t_figure *bishop)
{
	return ((king->i + king->j == bishop->i + bishop->j) ||
			(bishop->i - king->i == bishop->j - king->j));
}

int				check_mate_from_rook(t_figure *king, t_figure *rook)
{
	return ((rook->i == king->i) || (rook->j == king->j));
}

int				check_mate_from_pawn(t_figure *king, t_figure *pawn)
{
	return (((pawn->i == king->i + 1) && (pawn->j + 1 == king->j)) ||
			((pawn->i == king->i + 1) && (pawn->j == king->j + 1)));
}
int				check_mate_from_queen(t_figure *king, t_figure *queen)
{
	return (check_mate_from_bishop(king, queen) || check_mate_from_rook(king, queen));
}

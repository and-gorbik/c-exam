#ifndef CHECK_MATE_H
#define CHECK_MATE_H


#include <unistd.h>
#include <stdlib.h>
#include "figure.h"

int				check_mate_from_bishop(t_figure *king, t_figure *bishop);
int				check_mate_from_rook(t_figure *king, t_figure *rook);
int				check_mate_from_pawn(t_figure *king, t_figure *pawn);
int				check_mate_from_queen(t_figure *king, t_figure *queen);

#endif
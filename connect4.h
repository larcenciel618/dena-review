#ifndef CONNECT4_H
# define CONNECT4_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

extern	FILE	*fp;

bool	is_input_excuted(char **map, int int_num, char player);
bool	is_finish(char **map);
void	input_stone(char **map, int count);
void	print_map(char **map, FILE *mode);
void	is_valid_input(char **map, int count);

#endif

#ifndef SHIMOKU_H
# define SHIMOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

bool	execute_input(char **map, int int_num, char player);
void	input_stone(char **map, int count);
void	print_map(char **map);
void	is_valid_input(char **map, int count);

#endif

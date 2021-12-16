#include "connect4.h"

void	print_map(char **map)
{
		int y;

		y = 0;
		while (map[y] != NULL)
				printf("%s\n", map[y++]);
		printf("1234567\n");
		return ;
}

void	input_stone(char **map, int count)
{
		char	player;
		char	str_num[256];
		int		int_num;

		if (count % 2 == 0)
				player = 'A';
		else
				player = 'B';
		print_map(map);
		printf("[%c's turn]Please enter the number of columns\n", player);
		scanf("%s", str_num);
		int_num = atoi(str_num);
		while (execute_input(map, int_num, player) != true)
		{
				printf("[%c's turn]sorry,try again\n", player);
				scanf("%s", str_num);
				int_num = atoi(str_num);
		}
		return ;
}

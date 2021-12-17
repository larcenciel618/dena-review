#include "connect4.h"
char	matrix[2];

bool	is_finish(char **map)
{
	int	x;
	int y;
	int	i;
	int	count;

	x = (int)matrix[0] - '1';
	y = (int)matrix[1] - '1';
	i = 0;
	count = 1;
	while (map[y][i] != '\0')
	{
		if (map[y][i] != '+' && map[y][i] == map[y][i + 1])
		{
			if (++count == 4)
				return (true);
		}
		else
			count = 1;
		i++;
	}
	i = 0;
	count = 1;
	while (map[i + 1] != NULL)
	{
		if (map[i][x] != '+' && map[i][x] == map[i + 1][x])
		{
			if (++count == 4)
				return (true);
		}
		else
			count = 1;
		i++;
	}
	int	j;
	j = 0;
	if (x >= y)
	{
		j = 0;
		i = x - y; 
	}
	else
	{
		j = y - x;
		i = 0;
	}
	count = 1;
	while (map[j][i + 1] != '\0' && map[j + 1] != NULL)
	{
		if (map[j][i] != '+' && map[j][i] == map[j + 1][i + 1])
		{
			if (++count == 4)
				return (true);
		}
		else
			count = 1;
		j++;
		i++;
	}
	if ((6 - x) > y)
	{
		j = 0;
		i = x + y;
	}
	else
	{
		j = y - (6 - x);
		i = 6;
	}
	count = 1;
	while (i != 0 && map[j + 1] != NULL)
	{
		if (map[j][i] != '+' && map[j][i] == map[j + 1][i - 1])
		{
			if (++count == 4)
				return (true);
		}
		else
			count = 1;
		j++;
		i--;
	}
	return (false);
}

bool	is_input_executed(char **map, int i, char stone)
{
	int	y;

	if (i < 1 || 7 < i)
		return (false);
	i --;
	y = 0;
	while (y < 6 && map[y][i] == '+')
		y++;
	if (y == 0)
		return (false);
	else
		map[y - 1][i] = stone;
	matrix[0] = i + '1';
	matrix[1] = (y - 1) + '1';
	fprintf(fp, "\nPlayer[%c]:%c\n\n", stone, matrix[1]);
	print_map(map, fp);
	return (true);
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
		print_map(map, NULL);
		printf("[%c's turn]Please enter the number of columns(1..7)\n", player);
		scanf("%s", str_num);
		int_num = atoi(str_num);
		while (is_input_executed(map, int_num, player) != true)
		{
				printf("[%c's turn]sorry,try again(1..7)\n", player);
				scanf("%s", str_num);
				int_num = atoi(str_num);
		}
		return ;
}

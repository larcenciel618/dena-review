#include "connect4.h"
int		fd;
char	matrix[2];

void	clean_up(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
		free(map[y++]);
	free(map[y]);
	free(map);
	return ;
}

bool	execute_input(char **map, int i, char stone)
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
	write (fd, &stone, 1);
	write (fd, matrix, 2);
	write (fd, "\n", 1);
	return (true);
}

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

void	lets_play(char **map)
{
	int		count;
	char	player;

	count = 0;
	while ((count < 7 || is_finish(map) != true) && count < 42)
	{
		input_stone(map, count);
		count++;
	}
	if (count == 42 && is_finish(map) == false)
		printf("Draw\n");
	else
	{
		if (count % 2 == 1)
			player = 'A';
		else
			player = 'B';
		printf("[%c] Win\n", player);
	}
	print_map(map);
	return ;
}

char	**map_init(char **map)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	map = (char **)malloc(sizeof(char *) * 7);
	while (y < 6)
	{
		map[y] = (char *)malloc(sizeof(char) * 8);
		map[y][7] = '\0';
		y++;
	}
	map[y] = NULL;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (x < 7)
			map[y][x++] = '+';
		y++;
	}
	return (map);
}

int main(void)
{
	char	**map;

	system("rm history.txt > /dev/null");
	system("touch history.txt");
	fd = open("history.txt", O_WRONLY);
	map = NULL;
	map = map_init(map);
	lets_play(map);
	close(fd);
	clean_up(map);
	system("echo \"stone input\" >> history.txt");
	return (0);
}

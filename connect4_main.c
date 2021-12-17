#include "connect4.h"
FILE	*fp;
char	map[2];

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

void	lets_play(char **map)
{
	int		count;
	char	player;

	printf("\x1b[32mGame Start\x1b[0m\n");
	count = 0;
	while ((count < 7 || is_finish(map) != true) && count < 42)
	{
		input_stone(map, count);
		count++;
	}
	if (count == 42 && is_finish(map) == false)
	{

		printf("\n\n\x1b[36mDraw\x1b[0m\n");
		fprintf(fp, "\n\nDraw\n");
	}
	else
	{
		if (count % 2 == 1)
			player = 'A';
		else
			player = 'B';
		printf("\x1b[33m[%c] Win\x1b[0m\n", player);
		fprintf(fp, "\n\n[%c] Win\n", player);
	}
	print_map(map, NULL);
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
	fp = fopen("history.txt", "w");
	map = NULL;
	map = map_init(map);
	lets_play(map);
	fclose(fp);
	clean_up(map);
	return (0);
}

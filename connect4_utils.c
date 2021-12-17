#include "connect4.h"

void	print_map(char **map, FILE *mode)
{
		int y;

		y = 0;
		if (mode == NULL)
		{
			while (map[y] != NULL)
				printf("%s\n", map[y++]);
			printf("1234567\n");
		}
		else
		{
			while (map[y] != NULL)
				fprintf(mode, "%s\n", map[y++]);
			fprintf(mode, "1234567\n");
		}
		return ;
}


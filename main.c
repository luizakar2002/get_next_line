#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	int return_value;
	int fd;
	char *line = 0;

	fd = open("429", O_RDONLY);
	while ((return_value = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n",line);
		//printf("%d\n", return_value);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	printf("%d", return_value);
	return (0);
}

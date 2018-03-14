#include "libft.h"

int main()
{
	char *line;
	char *buffer = ft_strdup("first\nsecond\nthird\n");
	while (ft_get_line(&buffer, &line))
	{
		ft_printf("buffer: %s\n", buffer);
		ft_printf("line: %s\n", line);
	}
	return (0);
}

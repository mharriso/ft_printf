
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

static	char			*ft_joinchr(char const *s1, char c, size_t len)
{
	char		*s;
	size_t		i;

	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
		s[i++] = (*s1) ? *s1++ : c;
	s[i] = '\0';
	return (s);
}

int	get_next_line(int fd, char **line)
{
	char		buffer;
	int			res;
	char		*tmp;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE != 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	len = 0;
	while ((res = read(fd, &buffer, BUFFER_SIZE)) > 0 && buffer != '\n')
	{
		if (!(tmp = ft_joinchr(*line, buffer, ++len)))
			return -1;
		free(*line);
		*line = tmp;
	}
	return (res);
}

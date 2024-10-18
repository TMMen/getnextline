#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		free(buffer[fd]);
		return (buffer[fd] = NULL, NULL);
	}
	buffer[fd] = ft_read_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = ft_fill_line(buffer[fd]);
	buffer[fd] = ft_upd_buffer(buffer[fd]);
	return (line);
}

char	*ft_read_file(char *buff_old, int fd)
{
	char	*buff_new;
	int		chars_read;

	if (!buff_old)
		buff_old = ft_calloc(1, 1);
	buff_new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff_new)
		return (NULL);
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, buff_new, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buff_old);
			free(buff_new);
			return (NULL);
		}
		buff_new[chars_read] = 0;
		buff_old = ft_free_n_join(buff_old, buff_new);
		if (ft_strchr(buff_new, '\n'))
			break ;
	}
	free(buff_new);
	return (buff_old);
}

char	*ft_fill_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	ft_strlcpy(line, buffer, i);
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_upd_buffer(char *buff_old)
{
	int		i;
	char	*buff_new;

	i = 0;
	while (buff_old[i] && buff_old[i] != '\n')
		i++;
	if (!buff_old[i])
	{
		free(buff_old);
		return (NULL);
	}
	buff_new = ft_calloc((ft_strlen(buff_old) - i + 1), sizeof(char));
	ft_strlcpy(buff_new, buff_old + i + 1, ft_strlen(buff_old) - i + 1);
	free(buff_old);
	return (buff_new);
}

char	*ft_free_n_join(char *str1, char *str2)
{
	char	*str_tmp;

	str_tmp = ft_strjoin(str1, str2);
	free(str1);
	return (str_tmp);
}

/* #include <stdio.h>
#include <fcntl.h>

int	jo(void)
{

	return (0, 2, 1);
}

int main(void)
{
	int fd = open("fou.txt", O_RDONLY | O_CREAT);
	printf("%s", get_next_line(fd));
	printf("%i\n", jo());

} */

/* cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c && ./a.out | cat -e */

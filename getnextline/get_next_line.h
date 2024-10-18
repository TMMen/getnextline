#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_file(char *buff_old, int fd);
char	*ft_fill_line(char *buffer);
char	*ft_upd_buffer(char *buff_old);
char	*ft_free_n_join(char *str1, char *str2);

char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif

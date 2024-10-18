#include "get_next_line.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str_new;
	int		len;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	len = (int)ft_strlen(str1) + (int)ft_strlen(str2);
	str_new = (char *)malloc((len + 1) * sizeof(char));
	if (!str_new)
		return (NULL);
	i = 0;
	while (*str1)
	{
		str_new[i] = *str1;
		str1++;
		i++;
	}
	while (*str2)
	{
		str_new[i] = *str2;
		str2++;
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	if (((count * size) / size) != count)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (src[i] && i < (int)dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:46:08 by victorgiord       #+#    #+#             */
/*   Updated: 2022/11/15 12:20:26 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s_s1;
	int		s_s2;
	int		i;
	char	*result;

	i = 0;
	s_s1 = ft_strlen(s1);
	s_s2 = ft_strlen(s2);
	result = malloc((s_s1 + s_s2 + 1) * sizeof(char));
	if (!result || !s1 || !s2)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		s_s1;
	int		s_s2;
	int		i;
	char	*result;

	i = 0;
	s_s1 = ft_strlen(s1);
	s_s2 = ft_strlen(s2);
	result = malloc((s_s1 + s_s2 + 1) * sizeof(char));
	if (!result || !s1 || !s2)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2 && n-- > 0)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*src)
		str[i++] = *src++;
	str[i] = '\0';
	return (str);
}

int	isCharInString(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == str[i])
		return (i);
	return (-1);
}

char	*get_left_str(char *str, char c)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	i++;
	result = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}

char **split_first_char(char *str, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char **)malloc((2) * sizeof(char *));
	if (!result)
		return (NULL);
	while (str[i] != c)
		i++;
	result[0] = (char *)malloc((i + 1 + 1) * sizeof(char));
	result[1] = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!result[0] || !result[1])
		return (NULL);
	i = 0;
	while (str[i] != c)
	{
		result[0][i] = str[i];
		i++;
	}
	result[0][i] = c;
	result[0][i++ + 1] = '\0';
	while (str[i])
		result[1][j++] = str[i++];
	result[1][j] = '\0';
	return(result);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*char_src;
	char	*char_dst;

	char_src = (char *)src;
	char_dst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src && (src + n) > dst)
		while (n--)
			*(char_dst + n) = *(char_src + n);
	else
	{
		while (n--)
		{
			*(char_dst++) = *(char_src++);
		}
	}
	return (dst);
}
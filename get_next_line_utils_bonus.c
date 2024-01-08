/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:04:30 by plangloi          #+#    #+#             */
/*   Updated: 2023/12/18 15:58:55 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, int len)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;
	int		lens1;
	int		lens2;

	i = -1;
	j = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (++i < lens1)
		join[i] = s1[i];
	while (++j < lens2)
		join[i + j] = s2[j];
	join [i + j] = '\0';
	return (free (s1), join);
}

char	*ft_strchr(char *s, int c)

{
	unsigned int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == 0)
			return (NULL);
		i++;
	}
	return ((char *) s + i);
}

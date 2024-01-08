/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:21:36 by plangloi          #+#    #+#             */
/*   Updated: 2023/12/18 14:43:55 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_check_line(char *line, int fd)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE +1);
	if (!temp)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	while (!ft_strchr(line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), free(temp), NULL);
		temp[bytes_read] = '\0';
		line = ft_strjoin(line, temp);
	}
	return (free(temp), line);
}

char	*ft_clean_static(char *tampon)
{
	int		i;
	int		len;
	char	*new_tampon;

	i = 0;
	len = ft_strlen(tampon);
	while (tampon[i] && tampon[i] != '\n')
		i++;
	if (tampon[i] == '\n')
		new_tampon = ft_strndup(tampon + i + 1, len - i);
	else
		new_tampon = ft_strndup(tampon + i, len - i);
	free (tampon);
	return (new_tampon);
}

char	*ft_save_line(char *tampon)
{
	int		i;
	char	*line;

	i = 0;
	if (!tampon)
		return (NULL);
	while (tampon[i] && tampon[i] != '\n')
		i++;
	if (tampon[i] == '\n')
		line = ft_strndup (tampon, i + 1);
	else
		line = ft_strndup (tampon, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tampon[4096];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tampon[fd] = ft_check_line(tampon[fd], fd);
	if (!tampon[fd] || tampon[fd][0] == 0)
	{
		free(tampon[fd]);
		tampon[fd] = NULL;
		return (NULL);
	}
	line = ft_save_line(tampon[fd]);
	if (!line || line[0] == 0)
		return (free(line), free(tampon[fd]), NULL);
	tampon[fd] = ft_clean_static(tampon[fd]);
	if (tampon[fd] && tampon[fd][0] == 0)
	{
		free(tampon[fd]);
		tampon[fd] = NULL;
	}
	return (line);
}

/* # include <stdio.h>
# include <fcntl.h>

void read_files(const char *files) {
    int fd;
    char *line;

    fd = open(files, O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    while ((line = get_next_line(fd)) != NULL) {
        printf("Ligne lue (de %s) : %s\n", files, line);
        free(line);
    }
    close(fd);
}

int main() {
    read_files("testgnl/fd1.txt");
    read_files("testgnl/fd2.txt");
    read_files("testgnl/fd3.txt");
    read_files("testgnl/fd4.txt");
    read_files("testgnl/fd5.txt");

    return 0;
} */
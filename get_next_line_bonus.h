/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:07:39 by plangloi          #+#    #+#             */
/*   Updated: 2023/12/18 15:57:27 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*ft_strndup(char *s, int len);
int		ft_strlen(char *str);
char	*ft_check_line(char *line, int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_clean_static(char *tampon);
char	*ft_save_line(char *tampon);
#endif
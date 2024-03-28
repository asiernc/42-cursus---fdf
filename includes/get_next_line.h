/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:14:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/06 13:09:46 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 214748
# endif

int		get_next_line(int fd, char **line);
/*char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_read_line(char *str);
char	*ft_substr_gnl(char *buffer);

void	*ft_calloc_gnl(size_t len, size_t size);
void	ft_bzero_gnl(void *str, size_t len);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *str, int c);*/

#endif

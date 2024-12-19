/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:39:11 by sozbek            #+#    #+#             */
/*   Updated: 2024/12/15 13:51:57 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *buffer, char *tmp);
size_t	ft_strlen(char *str);
int		ft_newline_check(char *str);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:12:59 by tday              #+#    #+#             */
/*   Updated: 2023/09/03 21:11:08 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

void	free_null(char **mem_ptr);
char	*gnl_empty_str(void);
char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*extract_line(int newline_pos, char **static_buffer);
char	*read_line(int fd, char **static_buffer, char *temp_read_buffer);
char	*gnl_substr(char const *str, unsigned int start_index, size_t max_len);
size_t	gnl_strlen(const char *s);

#endif

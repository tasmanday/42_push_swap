/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:46:36 by tmitchel          #+#    #+#             */
/*   Updated: 2023/07/16 19:08:19 by tmitchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

double	ft_abs(double n);
float	ft_fabs(float n);
int		ft_count_words(const char *input_str, char delimeter);
int		ft_round_up(float number);
void	ft_swap(float *a, float *b);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
long	ft_atolong(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	**ft_split(const char *str, char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_bzero(void *pointer, size_t n);
void	*ft_calloc(size_t number, size_t size);
void	*ft_memset(void *pointer, int c, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_len);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_buff_len);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>   		        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:16:41 by tday              #+#    #+#             */
/*   Updated: 2023/08/29 18:05:22 by tday     	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
gnl_strchr searches a null-terminated string for the first occurance of a given 
character
if the character is found, returns a pointer to that character
if the character is not found, returns a null pointer (NULL) 

c = character (int variable as it uses ascii)
str = string
*/

char	*gnl_strchr(const char *str, int c)
{
	const char	*ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	if ((char)c == '\0')
		return ((char *)ptr);
	return (NULL);
}

/*
gnl_strlen counts the number of characters in a string and returns that number
(stops counting at null terminator '\0')

str = string
*/

size_t	gnl_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
gnl_strdup allocates memory and copies a source string to a destination string
source string must be null-terminated

src = source string
len = length of source string
dest = destination string

char	*gnl_strdup(char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = gnl_strlen(src) + 1;
	dest = (char *) malloc((len) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
*/

/*
gnl_strjoin allocates memory and returns a new string, which is the result of the
concatenation of s1 and s2

s1 = string 1
s2 = string 2
result = joined strings
len = total lenth of strings + 1 for '\0'
*/

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * (len));
	if (!result)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			result[i] = s1[i];
	else
		i = 0;
	j = -1;
	if (s2)
		while (s2[++j])
			result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}

/*
gnl_substr allocates memory and returns a substring from the string ’str’
The substring begins at index ’start_index’ and is of maximum size ’sub_len’
returns the substring or NULL if malloc fails

str = original string
start_index = start index of the substring
max_len = maximum length of substring
sub = substring
*/

char	*gnl_substr(char const *str, unsigned int start_index, size_t max_len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = gnl_strlen(str);
	if (start_index >= str_len)
	{
		start_index = str_len;
		max_len = 0;
	}
	else if (start_index + max_len > str_len)
		max_len = str_len - start_index;
	sub = (char *) malloc((max_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (str[start_index + i] != '\0' && i < max_len)
	{
		sub[i] = str[start_index + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
gnl_empty_str allocates a single byte of memory and sets it to '\0' 
it then returns the string.
this is used to initialise the static_buffer to an empty string in
get_next_line
*/

char	*gnl_empty_str(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

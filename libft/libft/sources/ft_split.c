/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitchel <tmitchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:23:57 by tday   	       #+#    #+#             */
/*   Updated: 2023/07/15 21:41:41 by tday	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
allocates memory and returns an array of strings obtained by splitting the 
original using the character ’delimeter’ as a delimiter
the array must end with a NULL pointer

input_str = original string
delimeter = delimiter character
word = substring formed after splitting
len = length of original string
result = array of words
i, j, & k = itterators
*/

#include "libft.h"

char	*allocate_word(const char *input_str, char delimeter, int *i)
{
	char	*word;
	int		j;
	int		k;

	j = 0;
	while ((input_str[*i + j] != '\0') && (input_str[*i + j] != delimeter))
	{
		j++;
	}
	word = (char *) malloc((j + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	k = 0;
	while ((input_str[*i] != '\0') && (input_str[*i] != delimeter))
	{
		word[k] = input_str[*i];
		k++;
		(*i)++;
	}
	word[k] = '\0';
	return (word);
}

int	count_words(const char *input_str, char delimeter)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (input_str[i] != '\0')
	{
		while (input_str[i] == delimeter && input_str[i] != '\0')
			i++;
		if (input_str[i] != delimeter && input_str[i] != '\0')
		{
			count++;
			while (input_str[i] != delimeter && input_str[i] != '\0')
				i++;
		}
	}
	return (count);
}

void	free_allocated(char **result, int j)
{
	while (j >= 0)
	{
		free (result[j]);
		j--;
	}
	free (result);
}

char	**ft_split(const char *input_str, char delimeter)
{
	char	**result;
	int		i;
	int		j;
	int		word_count;

	i = 0;
	j = 0;
	word_count = count_words(input_str, delimeter);
	result = (char **) malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (input_str[i] != '\0' && j < word_count)
	{
		while (input_str[i] == delimeter)
			i++;
		result[j] = allocate_word(input_str, delimeter, &i);
		if (!result[j])
		{
			free_allocated(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}

/*
int	main(void)
{
	char	*input_str;
	char	delimeter;
	char	**result;
	int		i;

	i = 0;
	input_str = "this is a test string";
	delimeter = ' ';
	result = ft_split(input_str, delimeter);
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
*/
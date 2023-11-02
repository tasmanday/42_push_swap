/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:16:11 by tday              #+#    #+#             */
/*   Updated: 2023/11/02 13:31:12 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft/includes/libft.h"
#include "../libft/ft_printf/includes/libftprintf.h"

/*

int	check_errors(int argc, char *argv[]);


Summary
The check_errors function is responsible for validating the command line
arguments passed to the program. It checks for non-numeric arguments, arguments
outside the integer range, and duplicate arguments.

Code Analysis

Inputs
argc: an integer representing the number of command line arguments.
argv: an array of strings representing the command line arguments.

Flow
1. Check if the number of arguments is less than or equal to 2. If so, return -1
to indicate an error.
2. Iterate over each argument starting from index 1.
3. Call the check_non_numeric function to check if the argument is non-numeric.
If it is, return -1.
4. Call the check_int_range function to check if the argument is outside the
integer range. If it is, return -1.
5. Call the check_duplicate function to check if there are any duplicate
arguments. If there are, return -1.
6. Increment the index and repeat steps 3-5 until all arguments have been
checked.
7. If no errors are found, return 0 to indicate success.

Outputs
Returns 0 if all the command line arguments are valid.
Returns -1 if there are any errors in the command line arguments.

*/
int	check_errors(int argc, char *argv[])
{
	int		i;

	if (argc <= 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (check_non_numeric(argv[i]) == -1)
			return (-1);
		if (check_int_range(argv[i]) == -1)
			return (-1);
		if (check_duplicate(i, argc, argv) == -1)
			return (-1);
		i++;
	}
	return (0);
}

/*

int	check_non_numeric(const char *arg);

Summary
The check_non_numeric function is responsible for checking if a given string
argument contains only numeric characters. If the argument contains any
non-numeric characters, the function prints an error message and returns -1.
Otherwise, it returns 0 to indicate that the argument is numeric.

Code Analysis

Inputs
arg: a string representing the argument to be checked for non-numeric
characters.

Flow
1. Initialize a variable j to 0.
2. Iterate over each character in the arg string until the end of the string
is reached.
3. Check if the current character is not a digit using the ft_isdigit function
from the libft library.
4. If the character is not a digit, print an error message using the ft_printf
function from the libftprintf library and return -1.
5. Increment the j variable to move to the next character in the string.
6. Repeat steps 3-5 until all characters in the string have been checked.
7. If no non-numeric characters are found, return 0 to indicate success.

Outputs
Returns 0 if the argument contains only numeric characters.
Returns -1 and prints an error message if the argument contains any non-numeric
characters.

*/
int	check_non_numeric(const char *arg)
{
	int	j;

	if (arg == NULL || *arg == '\0')
		return (-1);
	j = 0;
	while (arg[j] != '\0')
	{
		if (!ft_isdigit(arg[j]) && arg[j] != '-')
		{
			ft_printf("Error: non numeric argument\n");
			return (-1);
		}
		j++;
	}
	return (0);
}

/*

int	check_int_range(const char *arg);

Summary
The check_int_range function is responsible for checking if a given string
argument is within the range of integers. If the argument is outside the
range, the function prints an error message and returns -1. Otherwise, it
returns 0 to indicate that the argument is within the range.

Code Analysis

Inputs
arg: a string representing the argument to be checked for being within the
range of integers.

Flow
1. Convert the string argument to a long integer using the ft_atolong function
from the libft library.
2. Check if the converted number is less than the minimum value of an integer
or greater than the maximum value of an integer.
3. If the number is outside the range, print an error message using the
ft_printf function from the libftprintf library and return -1.
4. If the number is within the range, return 0 to indicate success.

Outputs
Returns 0 if the argument is within the range of integers.
Returns -1 and prints an error message if the argument is outside the range of
integers.

*/
int	check_int_range(const char *arg)
{
	long	num;

	if (arg == NULL || *arg == '\0')
		return (-1);
	num = ft_atolong(arg);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_printf("Error: argument outside integer range\n");
		return (-1);
	}
	return (0);
}

/*

int	check_duplicate(int i, int argc, char *argv[]);

Summary
The check_duplicate function is responsible for checking if there are any
duplicate arguments in the command line arguments passed to the program.
If a duplicate argument is found, the function prints an error message and
returns -1. Otherwise, it returns 0 to indicate that there are no duplicate
arguments.

Code Analysis

Inputs
i: an integer representing the index of the argument to be checked for
duplicates.
argc: an integer representing the number of command line arguments.
argv: an array of strings representing the command line arguments.

Flow
1. Initialize a variable k to i + 1.
2. Iterate over each argument starting from index k until the end of the
arguments.
3. Compare the argument at index i with the argument at index k using the
ft_strcmp function from the libft library.
4. If the arguments are equal, print an error message using the ft_printf
function from the libftprintf library and return -1.
5. Increment the k variable to move to the next argument.
6. Repeat steps 3-5 until all arguments have been checked.
7. If no duplicate arguments are found, return 0 to indicate success.

Outputs
Returns 0 if there are no duplicate arguments.
Returns -1 and prints an error message if duplicate arguments are found.

*/
int	check_duplicate(int i, int argc, char *argv[])
{
	int	k;

	k = i + 1;
	while (k < argc)
	{
		if (ft_strcmp(argv[i], argv[k]) == 0)
		{
			ft_printf("Error: duplicate arguments\n");
			return (-1);
		}
		k++;
	}
	return (0);
}

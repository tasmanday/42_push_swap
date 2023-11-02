/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:15:51 by tday              #+#    #+#             */
/*   Updated: 2023/09/03 22:35:34 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
get_next_line reads content from a given file descriptor and returns one line at
a time upon each call.

fd = the file descriptor, stdin is 0, stdout is 1, strerror is 2, and other
files are given a number >2 by the computer as their file descriptor.
static_buffer = a buffer used to store the data read from the fd, it is a static
variable meaning that its value persists across multiple function calls.
temp_read_buffer = a temporary buffer that is used to read fresh chuncks of data
from the fd, afterwards, the content of this buffer is appended to the
'static_buffer'
next_line = a pointer to the string that is created by replacing the first
instance of a '\n' in the file with a '\0'

the function returns 'NULL' if there are any errors with the fd, the
BUFFER_SIZE, memory allocation, or if it is at the end of the file.

if the static buffer hasn't been initialised before (first time get_next_line
has been called), it is initialised with an empty string.

the next_line is read and extracted from the fd in the process explained below
with the read_line and extract_line functions.

after reading the line the temp_read_buffer is no longer needed, so it's freed
and set to null with free_null.

the function returns a pointer to the next line and the remainding read data
after the '\n' is kept in the static_buffer for the next time that the
function is called.
*/

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*temp_read_buffer;
	char		*next_line;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_read_buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!temp_read_buffer)
		return (NULL);
	if (!static_buffer)
		static_buffer = gnl_empty_str();
	next_line = read_line(fd, &static_buffer, temp_read_buffer);
	free_null(&temp_read_buffer);
	return (next_line);
}

/*
free_null frees the memory associated with the given pointer and then sets that
pointer to NULL to avoid the possibility of using or dereferencing a dangling
pointer.
The function takes a pointer to a pointer to char (char **mem_ptr) as its
argument because it is intended to modify the original pointer's value, so it
requires a pointer to that pointer.
*/

void	free_null(char **mem_ptr)
{
	if (*mem_ptr != NULL)
	{
		free(*mem_ptr);
		*mem_ptr = NULL;
	}
}

/*
read_line reads content from the file descriptor until a '\n' is encountered or
until the end of the file. it stores remaining data from previous reads that
didn't include a newline to the static buffer.
it returns the next line from the file or the remaining content if no newline is
found.

fd = file descriptor
**static_buffer = pointer to the static buffer that holds the information read
from the fd, as it is static the data stored here can be passed to and modified
by multiple different functions, multiple times
temp_read_buffer = a temporary buffer used for reading new content from the fd

bytes_read = a count of the bytes read from the fd, this is the output of the
read function
updated_buffer = a temporary buffer that stores the concatination of the
static_buffer and the new data read from the file (temp_read_buffer).
the static_buffer is then freed and replaced with the updated_buffer
newline_ptr = a pointer to the first occurance of '\n' in the static buffer

before reading new content it first checks if there is already a '\n' in the
static_buffer

if it doesn't find a '\n' it will continue to read BUFFER_SIZE bytes from the fd
into the temp_read_buffer and adding them to the static_buffer until it finds a
'\n', or it gets to the end of the file (EOF), or there is an error

if a '\n' is found extract_line extracts the line from the static_buffer and
updates the static_buffer to begin after that line.
by passing (newline_ptr - *static_buffer + 1) we give extract_line the position
of the '\n' as an integer of bytes rather than the memory location.
newline_ptr (memory location of '\n') - *static_buffer (start of string) gives
the number of bytes before the '\n', and the +1 gives the '\n' as well.
*/

char	*read_line(int fd, char **static_buffer, char *temp_read_buffer)
{
	ssize_t	bytes_read;
	char	*updated_buffer;
	char	*newline_ptr;

	newline_ptr = gnl_strchr(*static_buffer, '\n');
	updated_buffer = NULL;
	bytes_read = 0;
	while (!newline_ptr)
	{
		bytes_read = read(fd, temp_read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free_null(static_buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			return (extract_line(bytes_read, static_buffer));
		temp_read_buffer[bytes_read] = '\0';
		updated_buffer = gnl_strjoin(*static_buffer, temp_read_buffer);
		free_null(static_buffer);
		*static_buffer = updated_buffer;
		newline_ptr = gnl_strchr(*static_buffer, '\n');
	}
	return (extract_line(newline_ptr - *static_buffer + 1, static_buffer));
}

/*
extract_line extracts the next line (up to and including '\n') from the 
static_buffer, updates the char *static_buffer to begin after the extracted
line, and then returns the extracted line.

newline_pos = position of the first '\n' in the static_buffer, also represents
the lenght in bytes of the current line including the '\n' character.
**static_buffer = pointer to the static buffer that holds the information read
from the fd, as it is static the data stored here can be passed to and modified
by multiple different functions, multiple times.

remainder_buffer = a temporary buffer used to store the remaining content from
the static_buffer that follows the current line
current_line = pointer to the string that is extracted from the static_buffer by
changing the first instance of '\n' to '\0'

if there is no '\n' or there is an error (newline_pos <= 0) it either returns
NULL or sets current_line to the static_buffer and returns current_line.

if there is a '\n' gnl_substr extracts the data in the static_buffer after the
'\n' and stores it in remainder_buffer.
it then sets the current line to the start of the static_buiffer and changes
the first instance of '\n' to '\0' ending the string at the end of the current
line and separating it fromk the rest of the data in static_buffer.
it then updates the static buffer to point to the remainder_buffer (the data
after the current_line)
finally it returns the current_line.
*/

char	*extract_line(int newline_pos, char **static_buffer)
{
	char	*remainder_buffer;
	char	*current_line;

	remainder_buffer = NULL;
	if (newline_pos <= 0)
	{
		if (**static_buffer == '\0')
		{
			free_null(static_buffer);
			return (NULL);
		}
		current_line = *static_buffer;
		*static_buffer = NULL;
		return (current_line);
	}
	remainder_buffer = gnl_substr(*static_buffer, newline_pos, BUFFER_SIZE);
	current_line = *static_buffer;
	current_line[newline_pos] = '\0';
	*static_buffer = remainder_buffer;
	return (current_line);
}

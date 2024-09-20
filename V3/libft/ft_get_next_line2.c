#include "libft.h"

char	*ft_output_gnl(char **next_line, int position, int bytes);
void	ft_free_gnl(char **p);
int	ft_strlen_gnl(char *s);
int	ft_strchr_gnl(char *s, int c, int flag);
char	*ft_strnjoin_gnl(char *s1, char *s2, int n);
char	*ft_strndup_gnl(char *input, int n);
void	*ft_calloc_gnl(size_t nelem, size_t elsize);
char	*ft_update_nl_gnl(char **next_line, int position);
char	*ft_output_gnl(char **next_line, int position, int bytes);


void	ft_free_gnl(char **p)
/*
** free's a given pointer and set's it to NULL
*/
{
	free(*p);
	*p = NULL;
}

int	ft_strlen_gnl(char *s)
/*
** returns length of a string until '\0'
** if the string is NULL return is 0
*/
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr_gnl(char *s, int c, int flag)
/*
** finds char c in string s and returns its position as an integer
** if flag == 1 return is -5 when input string is NULL
** if flag == 0 return is -1 when input string is NULL
*/
{
	int	i;

	if (flag == 1 && s == NULL)
		return (-5);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strnjoin_gnl(char *s1, char *s2, int n)
/*
** joins two strings
** first string does not have o exist
** only n characters of the second string get copied
** output is a allocated string
*/
{
	char	*output;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s2[i2] == '\0')
		return (NULL);
	output = malloc(ft_strlen_gnl(s1) + n + 1);
	if (output == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[i2] != '\0' && i2 < n)
		output[i++] = s2[i2++];
	output[i] = '\0';
	if (s1)
		ft_free_gnl(&s1);
	return (output);
}

char	*ft_strndup_gnl(char *input, int n)
/*
** duplicates n characters from input into output
** output is a allocated string
*/
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = n;
	output = malloc(len + 1);
	if (output == NULL)
		return (NULL);
	while (input && input[i] != '\0' && i < n)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

void	*ft_calloc_gnl(size_t nelem, size_t elsize)
/*
** standard libft function
*/
{
	char			*ptr;
	unsigned int	i;
	size_t			x;

	i = 0;
	x = nelem * elsize;
	ptr = (char *)malloc(x);
	if (ptr == NULL)
		return (0);
	while (i < x)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_update_nl_gnl(char **next_line, int position)
/*
** updates *next_line to the not returned remainder of *next_line
*/
{
	char	*tmp;
	int		len;

	len = ft_strlen_gnl(*next_line) - position;
	tmp = ft_strndup_gnl(*next_line + position, len);
	ft_free_gnl(next_line);
	*next_line = tmp;
	return (*next_line);
}

char	*ft_output_gnl(char **next_line, int position, int bytes)
/*
** error managment in first if statement
** stores every character of *next_line until '/n' or '/0' into line
** calls ft_update_nl if '/n' is found
** line is a allocated string
*/
{
	char	*line;

	if (((bytes == 0 || bytes == -1) && *next_line == NULL) || position == -5)
	{
		if (*next_line)
			return (*next_line);
		return (NULL);
	}
	line = NULL;
	if (position == -1)
		position = ft_strlen_gnl(*next_line);
	else
		position++;
	line = ft_strndup_gnl(*next_line, position);
	if (position == ft_strlen_gnl(*next_line))
		ft_free_gnl(next_line);
	else
		*next_line = ft_update_nl_gnl(next_line, position);
	return (line);
}

char	*ft_get_next_line2(int fd)
/*
** reads into buff and hands the whole buff to next_line
** until '/n' is found, end of file is reached or error in read
** next_line: stores everything from the past reads that was never returned
** buff: where read read's to
** position: stores the position of '/n', will be -1 if no '/n' found and -5 if next_line == NULL
** bytes: stores the output of read
*/
{
	static char	*next_line;
	char		*buff;
	int			position;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
		return (NULL);
	buff = NULL;
	position = ft_strchr_gnl(next_line, '\n', 0);
	while (position == -1 && position != -5)
	{
		buff = ft_calloc_gnl(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
			break ;
		next_line = ft_strnjoin_gnl(next_line, buff, bytes);
		position = ft_strchr_gnl(next_line, '\n', 1);
		ft_free_gnl(&buff);
	}
	ft_free_gnl(&buff);
	return (ft_output_gnl(&next_line, position, bytes));
}
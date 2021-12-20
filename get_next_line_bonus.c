/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:33:57 by jnidorin          #+#    #+#             */
/*   Updated: 2021/12/20 19:34:04 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*ft_cutting is a function for a cyclic call to gnl
 * 1) move pointer to '\n'
 * 2) if there is no '\n' in file -> clean line. (Needed for null output)
 * 3) allocate memory for trash
 * 4) move i to first trash char entrance
 * 5) trash -> buff
*/
char	*ft_cutting(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	buff = malloc (sizeof(char) * (ft_strlen(str) - i));
	if (!buff)
		return (0);
	j = 0;
	i++;
	while (str[i])
	{
		buff[j++] = str[i++];
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

/*function prepares str for printing
 * 1) move i to '\n'
 * 2) allocate memory for str, extra slots for '\n' and '\0'
 * 3) str + \n -> buff
 */

char	*ft_completed_line(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

/*
 * 1) reads packs of chars (len = BUFFER_SIZE)
 * 2) readed pack -> ft_symbols_pack_check
 * 3) save last pack in buff. Adds \0
 */

char	*ft_trashed_readline(int fd, char *str)
{
	char	*buff;
	int		readed_bytes;

	readed_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!ft_symbols_pack_check(str) && readed_bytes != 0)
	{
		readed_bytes = read(fd, buff, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[readed_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

/*
 * Associating file descriptors with their remnants
 * fd = the number of the pointer storing the string reference (trash)
 * 4096 max fd amount in system
 */

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_trashed_readline(fd, str[fd]);
	if (!str[fd])
		return (0);
	buff = ft_completed_line(str[fd]);
	str[fd] = ft_cutting(str[fd]);
	return (buff);
}

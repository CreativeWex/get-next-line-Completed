/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jnidorin <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/20 18:00:51 by jnidorin		  #+#	#+#			 */
/*   Updated: 2021/12/20 18:05:27 by jnidorin         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buff;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buff = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	if (!buff)
		return (0);
	j = 0;
	i = 0;
	while (s1[j])
		buff[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buff[i++] = s2[j++];
	buff[i] = '\0';
	free(s1);
	return (buff);
}

int	ft_strlen(const char *p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	return (i);
}

// ft_symbols_pack_check сhecks pack of symbols for '\n'
// if there is no '\n' in pack returns 0
// returns memory adress(str from '\n' to end of str)

char	*ft_symbols_pack_check(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
	{
		if (!str[i])
			return (0);
		++i;
	}
	return ((char *)&str[i]);
}

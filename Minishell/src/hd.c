/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:49 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 01:24:03 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_cleaninput(char *src, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
		dest[j++] = src[i++];
	dest[i] = '\0';
	return (dest);
}

void	ft_hdmaker(char *str, int i, char c, t_index *index)
{
	char	*input;
	char	*tmp;
	int		fd;
	int		len;

	fd = open("v.txt", O_CREAT | O_WRONLY, 0644);
	i++;
	while (str[i])
		write(fd, &str[i++], 1);
	write(fd, "\n", 1);
	while (1)
	{
		input = readline("> ");
		len = ft_add_len(input, c);
		tmp = malloc(sizeof(char) * len + 1);
		tmp = ft_cleaninput(input, tmp);
		write(fd, tmp, len);
		write(fd, "\n", 1);
		if (ischar(input, 0, c))
			break ;
		free(tmp);
	}
	index->stdin = fd;
	close(fd);
}

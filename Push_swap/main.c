/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:11:46 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/23 12:21:45 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_select_sort(t_pile **pile)
{
	int	len;

	len = ft_lst_size(*pile);
	if (len == 2)
		sa(pile);
	else if (len == 3)
		sort_3_elements(pile);
	else if (len == 4)
		sort_4_elements(pile);
	else if (len == 5)
		sort_5_elements(pile);
	else
		ft_radix(pile);
	free_pile(pile);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *source)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_total;
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (len_total + 2));
	if (!dest)
		return (NULL);
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i++] = ' ';
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	main(int argc, char **argv)
{
	char	*string;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		string = ft_strdup("");
		while (argv[i])
			string = ft_strjoin(string, argv[i++]);
		if (string && check_num(string) && check_double(ft_split(string, ' '))
			&& ft_was(string) == 1)
			parser(string);
		else
			write(2, "Error\n", 6);
		free(string);
	}
	else
		return (0);
	return (1);
}

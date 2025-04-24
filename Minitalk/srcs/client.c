/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:10:35 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/23 22:59:32 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_g = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_g = 1;
}

void	send_char_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_g = 0;
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_g != 1)
			usleep(0);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR1, ack_handler);
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_char_to_server(pid, argv[2][i]);
			i++;
		}
		send_char_to_server(pid, '\0');
	}
	else
	{
		ft_printf("pas bon mon lapin\n");
		ft_printf("./client <pid> <message>\n");
		return (1);
	}
	return (0);
}

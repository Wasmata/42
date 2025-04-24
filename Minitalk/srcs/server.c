/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:10:40 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/23 23:24:36 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	process_char(char c)
{
	static char	*msg;
	char		*tmp;
	char		one_char[2];

	one_char[0] = c;
	one_char[1] = '\0';
	if (c == '\0')
	{
		if (msg)
		{
			ft_printf("%s\n", msg);
			free(msg);
			msg = NULL;
		}
	}
	else
	{
		tmp = msg;
		msg = ft_strjoin(msg, one_char);
		free(tmp);
	}
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	(void)context;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		process_char(c);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: bad format.\n");
		ft_printf("Try: ./server");
		return (1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("On att le message...\n");
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

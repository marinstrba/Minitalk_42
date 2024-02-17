/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:50 by mstrba            #+#    #+#             */
/*   Updated: 2024/02/17 11:53:09 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk/minitalk.h"

void	signal_handle_client(int sig);
void	init_signals(void);

int	main(void)
{
	__pid_t	pid;

	pid = getpid();
	printf("This is the id of the server: %d\n", pid);
	init_signals();
	while (1)
		pause();
	return (0);
}

void	signal_handle_client(int sig)
{
	static int				bit_position = 7;
	static unsigned char	current_char = 0;

	if (sig == SIGUSR1)
		current_char |= (1 << bit_position);
	bit_position--;
	if (bit_position < 0)
	{
		write(STDOUT_FILENO, &current_char, 1);
		write(STDOUT_FILENO, "\n", 1);
		bit_position = 7;
		current_char = 0;
	}
}

void	init_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = signal_handle_client;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		error_handler("Error setting SIGUSR1 handler.\n");
		exit (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		error_handler("Error setting SIGUSR2 handler.\n");
		exit (EXIT_FAILURE);
	}
}

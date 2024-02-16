/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:50 by mstrba            #+#    #+#             */
/*   Updated: 2024/02/16 15:38:12 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	signal_handle_client(int sig);

int	main(int argc, char	**argv)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = signal_handle_client;

	printf("This is the id of the server: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Error setting SIGUSR1 handler.");
		exit (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting SIGUSR2 handler.");
		exit (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}

void	signal_handle_client(int sig)
{
	
}

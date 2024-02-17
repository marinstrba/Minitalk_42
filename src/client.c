/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:40:57 by mstrba            #+#    #+#             */
/*   Updated: 2024/02/17 11:03:21 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../lib/libft/libft.h"
#include "../lib/minitalk/extra.h"

void	args_checker(int argc, char **argv);
void	send_message(__pid_t pid, char	*message);

int	main(int argc, char	**argv)
{
	__pid_t	server_pid;

	args_checker(argc, argv);
	server_pid = atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}

void	args_checker(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc != 3)
		error_handler("Invalid number of arguments.\n");
	while (argv[1][index])
		if (!ft_isdigit(argv[1][index++]))
			error_handler("Invalid server id.");
	if (*argv[2] == 0)
		error_handler("The message is empty.");
}

void	send_message(__pid_t pid, char	*message)
{
	int				nbr_of_bits;
	unsigned char	c;

	while (*message)
	{
		c = *message;
		nbr_of_bits = 8;
		while (nbr_of_bits--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		message++;
	}
}

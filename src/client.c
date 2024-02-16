/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:40:57 by mstrba            #+#    #+#             */
/*   Updated: 2024/02/16 15:46:39 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int	char_to_bin(char c, int pid);

int	main(int argc, char	**argv)
{
	int					server_id;
	char				*message;
	struct sigaction 	sa;

	if (argc != 3)
	{
		printf("Wrong number of arguments.\n");
		exit(-1);
	}
	else
	{
		
	}
	return (0);
}

int	char_to_bin(char c, int pid)
{
	
}

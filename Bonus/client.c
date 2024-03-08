/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:53 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/08 17:27:33 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_resive(int sig)
{
	write(1,"message sent\n",13);
}

void decmal_to_bin(unsigned int al, int id_pd)
{
	int i;
	int bit;

	i = 7;
	while (i>=0)
	{
		bit = al >> i & 1;
		if(bit == 0)
			kill(id_pd, SIGUSR1);
		else
			kill(id_pd, SIGUSR2);
		usleep(500);
		i--;
	}
}
int main(int argc, char const *argv[])
{
	pid_t id_pd;
	int i;

	if (argc != 3)
		return 0;
	id_pd = ft_atoi(argv[1]);
	if (id_pd < 1)
		return 0;
	i = 0;
	while (argv[2][i])
	{
		decmal_to_bin(argv[2][i], id_pd);
		i++;
	}
	signal(SIGUSR1,ft_resive);
	decmal_to_bin('\0', id_pd);
	return 0;
}

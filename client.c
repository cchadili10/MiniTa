/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:53 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/01 23:48:15 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void decmal_to_bin(int al, int id_pd)
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
		usleep(20);
		//printf("%d",bit);
		i--;
	}
	
	
}
int main(int argc, char const *argv[])
{
	pid_t id_pd;
	int i;

	id_pd = atoi(argv[1]);
	if (argc != 3)
		return 0;
	while (argv[2][i])
	{
		decmal_to_bin(argv[2][i], id_pd);
		//printf("\n");
		i++;
	}
	decmal_to_bin(10, id_pd);
	// printf("%c",10);
	return 0;
}

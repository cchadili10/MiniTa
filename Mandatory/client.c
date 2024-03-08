/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:53 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/08 22:09:54 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void decmal_to_bin(int al, int id_pd)
{
	int i;
	int bit;
 
	i = 7;
	while (i >= 0)
	{
		bit = al >> i & 1;
		if(bit == 0)
			kill(id_pd, SIGUSR1);
		else
			kill(id_pd, SIGUSR2);
		usleep(400);
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
	return 0;
}

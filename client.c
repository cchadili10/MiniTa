/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:53 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/01 17:44:09 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void rev_array(char *array, int i)
{
	int	x;
	int y;
	char swp;

	x = 0;
	while (i > x)
	{
		swp = array[x];
		array[x] = array[i-1];
		array[i-1] = swp;
		x++;
		i--;
	}
	
}
char	*decmal_to_bin(int ab)
{
	int y;
	char *array;
	int mod = 0;

	y = 0;
	array = malloc(8);
	if(!array)
		return NULL;
	while (ab > 0)
	{
		array[y] = 48 + (ab % 2);
		ab /= 2;
		y++;
	}
	array[y] = '\0';
	rev_array(array, y);
	return array;
}
void	ft_sent(int car,pid_t id_pd)
{
	char *array;
	int x;
	
	x = 0;
	array = decmal_to_bin(car);
	while (array[x])
	{
		if(array[x] == '1')
			kill(id_pd, SIGUSR2);
		else
			kill(id_pd, SIGUSR1);
		//break;
		printf("%c\n",array[x]);
		usleep(100);
		x++;
	}
	free(array);
	
}
void dunc_sh(int al)
{
	int i=7;

	while (i>=0)
	{
		int bit = al >> i & 1;
		
	printf("%d\n",bit);
	i--;
	}
	
}
int main(int argc, char const *argv[])
{
	// pid_t id_pd;
	// int i;

	// id_pd = atoi(argv[1]);
	// // printf("%d",id_pd);
	// if (argc != 3)
	// 	return 0;
	// while (argv[2][i])
	// {
	// 	ft_sent(argv[2][i], id_pd);
	// 	i++;
	// }
// bit =0;
 int bit = (1 << 6) ; //01000001 | 00000001  | 01000000÷

	
	//ft_sent(253,1);
	dunc_sh('A');
	printf("%d",bit);
	return 0;
}

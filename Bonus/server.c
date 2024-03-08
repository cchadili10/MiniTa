/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:49 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/08 23:54:24 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int s[4];

void free_array()
{
	s[0] = 0; 
	s[1] = 0; 
	s[2] = 0; 
	s[3] = 0; 
}
int decmal_to_bin(unsigned int al)
{
	int i;
	int bit;
	int x;

	i = 7;
	x = 0;
	while (i >= 0)
	{
		bit = al >> i & 1;
		if(bit == 1)
			x++;
		else
			return x;
		i--;
	}
	return x;
}
void	ft_print_car(int car, int pd_change)
{
	static int num_bit;
	static int check;
	static int j;
	
	if(pd_change == 1) num_bit = 0, check = 0, j = 0;
	if(check == 0)
	{
		num_bit = decmal_to_bin(car);
		if (num_bit > 0) check = 1;
	}
	if(check == 0) put_char(car);
	else
	{
		s[j] = car;
		j++;
		if (num_bit == 1)
		{
			put_str(s);
			free_array();
			check = 0;
			j = 0;
		}
		num_bit--;
	}
}
void sigusr_handler(int sig, siginfo_t *info, void *unsude)
{

	int nums[8] = {128,64,32,16,8,4,2,1};
	static int i;
	static int car;
	static int pd;
	static int	pd_change;
	
	if (pd == 0)
		pd = info->si_pid;
	if (pd != info->si_pid)
	{
		if (1 == 1) car = 0, i = 0, pd = info->si_pid, pd_change = 1;
		free_array();
	}
	if(sig == SIGUSR2)
		car += nums[i];
	i++;
	if(i == 8)
	{
		if(car == 0)
			kill(info->si_pid, SIGUSR1);
		ft_print_car(car, pd_change);
		if (1 == 1) i = 0 , car = 0, pd_change = 0; 
	}
	unsude = NULL;
}
int main() 
{
	struct sigaction	sa;
	char				*s;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigusr_handler;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	s = ft_itoa(getpid());
	write(1, s, sizeof(s));
	free(s);
	while(1)
		sleep(1);
	return 0;
}

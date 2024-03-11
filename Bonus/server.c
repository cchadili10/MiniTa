/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:49 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/11 16:19:21 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_array[4];

void	free_array(int *a, int *b, int *c, int x)
{
	*a = 0;
	*b = 0;
	*c = 0;
	if (x == 1)
	{	
		g_array[0] = 0;
		g_array[1] = 0;
		g_array[2] = 0;
		g_array[3] = 0;
	}
}

int	decmal_to_bin(unsigned int al)
{
	int	i;
	int	bit;
	int	x;

	i = 7;
	x = 0;
	while (i >= 0)
	{
		bit = al >> i & 1;
		if (bit == 1)
			x++;
		else
			return (x);
		i--;
	}
	return (x);
}

void	ft_print_car(int car, int pd_change)
{
	static int	num_bit;
	static int	check;
	static int	j;

	if (pd_change == 1)
		free_array(&num_bit, &j, &check, 1);
	if (check == 0)
	{
		num_bit = decmal_to_bin(car);
		if (num_bit > 0)
			check = 1;
	}
	if (check == 0)
		put_char(car);
	else
	{
		g_array[j] = car;
		j++;
		if (num_bit == 1)
		{
			put_str(g_array);
			free_array(&car, &j, &check, 0);
		}
		num_bit--;
	}
}

void	sigusr_handler(int sig, siginfo_t *info, void *unsude)
{
	static int	nums[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int	i;
	static int	car;
	static int	pd;
	static int	pd_change;

	if (pd == 0)
		pd = info->si_pid;
	if (pd != info->si_pid)
	{
		pd = info->si_pid;
		free_array(&car, &i, &pd_change, 1);
		pd_change = 1;
	}
	if (sig == SIGUSR2)
		car += nums[i];
	i++;
	if (i == 8)
	{
		if (car == 0)
			kill(info->si_pid, SIGUSR1);
		ft_print_car(car, pd_change);
		free_array(&car, &i, &pd_change,0);
	}
	unsude = NULL;
}

int	main(void)
{
	struct sigaction	sa;
	char				*s;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigusr_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	s = ft_itoa(getpid());
	write(1, s, sizeof(s));
	write(1, "\n", 1);
	free(s);
	while (1)
		sleep(1);
	return (0);
}

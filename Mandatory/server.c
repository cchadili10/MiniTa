/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:49 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/08 23:17:34 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void put_str(char c)
{
    write(1,&c,1);
}
void sigusr_handler(int sig, siginfo_t *info, void *unsude)
{
    static int car;
    static int  i;
    static int  pd;
    
    int nums[8] = {128,64,32,16,8,4,2,1};

    if (pd == 0)
        pd = info->si_pid;
    if (pd != info->si_pid)
    {
        i = 0;
        car = 0;
        pd = info->si_pid;
    }
    if(sig == SIGUSR2)
        car += nums[i];
    i++;
    if(i == 8)
    {
        put_str(car);
        i = 0;
        car = 0; 
    }
    unsude = NULL;
}
int main() {
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
    while(1) {
        sleep(1);
    }
    return 0;
}

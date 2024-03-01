/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:49 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/01 23:06:07 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void put_str(char c)
{
    write(1,&c,1);
}

int a[2];

void sigusr_handler(int sig)
{

    int nums[8] = {128,64,32,16,8,4,2,1};

    if(sig == SIGUSR1)
    {
        //printf("0\n");
    }
    else
    {
        //printf("1\n");
        a[1] += nums[a[0]%8];
    }
    a[0]++;
    if(a[0] % 8 == 0)
    {
        put_str(a[1]);
        a[1] = 0; 
    }
}
int main() {
    // Register signal handlers
    int num;
    signal(SIGUSR1, sigusr_handler);
    signal(SIGUSR2, sigusr_handler);

    printf("PID: %d\n", getpid());
    printf("Waiting for signals...\n");

    while(1) {
        sleep(1);
        //printf("%d\n",a);
    }

    return 0;
}

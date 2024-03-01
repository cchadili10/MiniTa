/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:49 by hchadili          #+#    #+#             */
/*   Updated: 2024/03/01 17:46:05 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a;

void sigusr1_handler(int sig){

    if(sin)
}
int main() {
    // Register signal handlers
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    printf("PID: %d\n", getpid());
    printf("Waiting for signals...\n");

    while(1) {
        sleep(1);
        printf("%d\n",a);
    }

    return 0;
}

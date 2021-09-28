/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <wjdzh8748@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:00:53 by dher              #+#    #+#             */
/*   Updated: 2021/09/28 06:25:22 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_buffer;

void	if_bit_recieved(int signum, siginfo_t *siginfo, void *void_arg)
{
	static int	client_pid;

	(void)void_arg;
	if (siginfo->si_pid != 0)
		client_pid = siginfo->si_pid;
	if (signum == SIGUSR1)
		g_buffer.word += 1 << (7 - g_buffer.bit_counter);
	g_buffer.bit_counter++;
	if (g_buffer.bit_counter >= 8)
	{
		ft_putchar_fd(g_buffer.word, 1);
		g_buffer.bit_counter = RESET;
		g_buffer.word = RESET;
	}
	kill(client_pid, SIGUSR1);
}

void	print_pid(void)
{
	ft_putstr_fd("server's PID : ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	ft_putstr_fd("\n", 1);
}

int	main(void)
{
	struct sigaction	action;

	g_buffer.bit_counter = RESET;
	g_buffer.word = RESET;
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = if_bit_recieved;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	print_pid();
	if ((sigaction(SIGUSR1, &action, NULL)) == -1)
		print_error();
	if ((sigaction(SIGUSR2, &action, NULL)) == -1)
		print_error();
	while (1)
		pause();
	return (0);
}

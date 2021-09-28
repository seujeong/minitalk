/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <wjdzh8748@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:00:37 by dher              #+#    #+#             */
/*   Updated: 2021/09/28 06:25:20 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_ack;

void	send_message_to_server(t_signal *client)
{
	int		index;

	index = 0;
	client->word = RESET;
	while (client->message[index])
		send_buffer_to_server(client, client->message[index++]);
	if (client->message[index] == '\0')
		exit(0);
}

void	send_buffer_to_server(t_signal *client, int buffer_to_send)
{
	client->bit_counter = 0b10000000;
	while (client->bit_counter)
	{
		if (client->bit_counter & buffer_to_send)
		{
			if (kill(client->server_pid, SIGUSR1) == -1)
				print_error();
		}
		else
		{
			if (kill(client->server_pid, SIGUSR2) == -1)
				print_error();
		}
		client->bit_counter >>= 1;
		while (!g_ack)
			usleep(10000);
		g_ack = 0;
	}
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
	g_ack = 1;
}

int	check_arguments(int argc)
{
	if (argc != 3)
	{
		print_error();
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_signal			client;
	struct sigaction	sact;

	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_handler;
	sigemptyset(&sact.sa_mask);
	sigaddset(&sact.sa_mask, SIGUSR1);
	sigaddset(&sact.sa_mask, SIGUSR2);
	if ((sigaction(SIGUSR1, &sact, NULL)) == -1)
		print_error();
	if ((sigaction(SIGUSR2, &sact, NULL)) == -1)
		print_error();
	client.server_pid = ft_atoi(argv[1]);
	client.message = argv[2];
	client.bit_counter = 0;
	if (check_arguments(argc) == -1)
		return (-1);
	send_message_to_server(&client);
	return (0);
}

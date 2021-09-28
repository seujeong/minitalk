/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <wjdzh8748@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:50:16 by dher              #+#    #+#             */
/*   Updated: 2021/09/28 06:25:23 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

# ifndef RESET
#  define RESET 0
# endif

typedef struct s_stack
{
	u_int8_t		word;
	u_int8_t		bit_counter;
	unsigned int	server_pid;
	char			*message;
}			t_signal;

void	print_error(void);
int		check_arguments(int argc);
void	send_message_to_server(t_signal *client);
void	send_buffer_to_server(t_signal *client, int buffer_to_send);
void	ft_handler(int signum, siginfo_t *siginfo, void *unused);
int		get_process_id(char	*pid_type_string, t_signal *client);
void	send_message_to_server(t_signal *client);
void	send_buffer_to_server(t_signal *client, int buffer_to_send);
void	ft_handler(int signum, siginfo_t *siginfo, void *unused);
int		check_arguments(int argc);
void	print_pid(void);
void	if_bit_recieved(int signum, siginfo_t *siginfo, void *void_arg);

#endif

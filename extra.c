/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <wjdzh8748@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:52:59 by dher              #+#    #+#             */
/*   Updated: 2021/09/28 06:25:21 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(void)
{
	ft_putstr_fd("error", 1);
	exit(-1);
}

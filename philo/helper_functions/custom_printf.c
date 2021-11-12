/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:38:30 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:38:32 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	custom_printf(const char *str, t_thread_info *thread_info)
{
	struct timeval	time_now;

	pthread_mutex_lock(&thread_info->global_data->lock_stdin);
	printf(
		"%u %d %s\n",
		get_time_now(),
		thread_info->index,
		str);
	pthread_mutex_unlock(&thread_info->global_data->lock_stdin);
	return (1);
}

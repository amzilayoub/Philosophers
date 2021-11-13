/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_helper_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:23:24 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 18:25:50 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	_watcher_helper_function(t_data *data, int i, int *min_eat_count)
{
	unsigned int	last_time_eat;
	unsigned int	time_now;

	last_time_eat = data->threads_data[i].last_time_eat;
	time_now = get_time_now();
	if (time_now - last_time_eat >= (unsigned int)data->args->time_to_die)
	{
		data->philo_died = TRUE;
		pthread_mutex_lock(&data->threads_data[i].is_eating);
		pthread_mutex_lock(&data->lock_stdin);
		died(&data->threads_data[i]);
		return (1);
	}
	if (data->args->number_of_times_each_philosopher_must_eat
		<= data->threads_data[i].eat_count)
		(*min_eat_count) += 1;
	return (0);
}

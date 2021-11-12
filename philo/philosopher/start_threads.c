/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:36:57 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:36:59 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void run_threads(t_data *data, int initiale_value,int inc)
{
	int	i;

	i = initiale_value;
	while (i < data->args->number_of_philosophers)
	{
		data->threads_data[i].global_data = data;
		data->threads_data[i].eat_count = 0;
		data->threads_data[i].last_time_eat = get_time_now();
		pthread_create(
			&data->threads_data[i].thread_id,
			NULL,
			philo,
			(void *)&data->threads_data[i]);
		pthread_detach(data->threads_data[i].thread_id);
		i += inc;
	}
}

void	start_threads(t_data *data)
{
	int	i;

	i = 1;
	run_threads(data, 1, 2);
	// while (i < data->args->number_of_philosophers)
	// {
	// 	data->threads_data[i].global_data = data;
	// 	data->threads_data[i].eat_count = 0;
	// 	data->threads_data[i].last_time_eat = get_time_now();
	// 	pthread_create(
	// 		&data->threads_data[i].thread_id,
	// 		NULL,
	// 		philo,
	// 		(void *)&data->threads_data[i]);
	// 	pthread_detach(data->threads_data[i].thread_id);
	// 	i += 2;
	// }
	usleep(100);
	run_threads(data, 1, 2);
	i = 0;
	while (i < data->args->number_of_philosophers)
	{
		data->threads_data[i].global_data = data;
		data->threads_data[i].eat_count = 0;
		data->threads_data[i].last_time_eat = get_time_now();
		pthread_create(
			&data->threads_data[i].thread_id,
			NULL,
			philo,
			(void *)&data->threads_data[i]);
		pthread_detach(data->threads_data[i].thread_id);
		i += 2;
	}
}

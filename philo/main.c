/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:34:15 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:34:19 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	watcher(t_data *data)
{
	int				i;
	int				min_eat_count;

	while (1)
	{
		i = -1;
		min_eat_count = 0;
		while (++i < data->args->number_of_philosophers)
		{
			if (_watcher_helper_function(data, i, &min_eat_count))
				return (1);
		}
		if (min_eat_count == data->args->number_of_philosophers
			&& data->has_must_eat_count)
		{
			data->philo_died = TRUE;
			pthread_mutex_lock(&data->lock_stdin);
			printf("Simulation ends\n");
			return (0);
		}
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	init(&data);
	if (parser(data, argc, argv))
		return (1);
	fill_data(data);
	start_threads(data);
	if (watcher(data))
		return (1);
	return (0);
}

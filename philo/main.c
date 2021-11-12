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

void	watcher(t_data *data)
{
	int				i;
	int				min_eat_count;

	while (1)
	{
		i = -1;
		min_eat_count = 0;
		while (++i < data->args->number_of_philosophers)
			_watcher_helper_function(data, i, &min_eat_count);
		if (min_eat_count == data->args->number_of_philosophers
			&& data->has_must_eat_count)
		{
			data->philo_died = TRUE;
			pthread_mutex_lock(&data->lock_stdin);
			printf("Simulation ends\n");
			exit(1);
		}
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	init(&data);
	if (parser(data, argc, argv))
	{
		exit(1);
	}
	fill_data(data);
	start_threads(data);
	watcher(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:35:48 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:35:52 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parser(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error();
	data->args->number_of_philosophers = ft_atoi(argv[1]);
	data->args->time_to_die = ft_atoi(argv[2]);
	data->args->time_to_eat = ft_atoi(argv[3]);
	data->args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->args->number_of_times_each_philosopher_must_eat
			= ft_atoi(argv[5]);
		data->has_must_eat_count = TRUE;
	}
	else
	{
		data->args->number_of_times_each_philosopher_must_eat = 0;
		data->has_must_eat_count = FALSE;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:38:43 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:38:52 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	custom_usleep(useconds_t time_to_sleep)
{
	unsigned int	start;

	start = get_time_now();
	usleep((time_to_sleep * 1e3) * 0.9);
	while (get_time_now() - start < time_to_sleep)
		continue ;
}

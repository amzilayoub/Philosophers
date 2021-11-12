/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_now.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:39:19 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:39:22 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned int	get_time_now(void)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return (convert_to_milisec(time_now));
}

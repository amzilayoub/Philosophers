/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:36:33 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:36:34 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	lock_forks(t_thread_info *thread_info)
{
	pthread_mutex_lock(&thread_info->fork);
	custom_printf("taken a fork", thread_info);
	pthread_mutex_lock(&thread_info->next_philo->fork);
	custom_printf("taken a fork", thread_info);
}

void	unlock_forks(t_thread_info *thread_info)
{
	pthread_mutex_unlock(&thread_info->fork);
	pthread_mutex_unlock(&thread_info->next_philo->fork);
}

void	*philo(void *args)
{
	t_thread_info	*thread_info;

	thread_info = (t_thread_info *)args;
	while (1)
	{
		lock_forks(thread_info);
		eating(thread_info);
		unlock_forks(thread_info);
		sleeping(thread_info);
		thinking(thread_info);
	}
	return (NULL);
}

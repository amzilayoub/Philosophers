/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_milisec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:38:20 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:38:21 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned int	convert_to_milisec(struct timeval time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

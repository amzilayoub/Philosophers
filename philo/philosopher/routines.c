#include "../include/philo.h"

void eating(t_thread_info *thread_info)
{
    custom_printf("is eating", thread_info);
    custom_usleep(thread_info->global_data->args->time_to_eat);
    gettimeofday(&thread_info->last_time_eat, NULL);
}

void sleeping(t_thread_info *thread_info)
{
    custom_printf("is sleeping", thread_info);
    custom_usleep(thread_info->global_data->args->time_to_sleep);
}

void thinking(t_thread_info *thread_info)
{
    custom_printf("is thinking", thread_info);
}

void died(t_thread_info *thread_info)
{
    custom_printf("died", thread_info);
}
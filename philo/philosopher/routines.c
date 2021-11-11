#include "../include/philo.h"

void eating(t_thread_info *thread_info)
{
    pthread_mutex_lock(&thread_info->is_eating);
    custom_printf("is eating", thread_info);
    thread_info->last_time_eat = get_time_now();
    custom_usleep(thread_info->global_data->args->time_to_eat);
    thread_info->eat_count += 1;
    pthread_mutex_unlock(&thread_info->is_eating);
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
    printf("%u %d %s\n", get_time_now() - g_process_starting_time, thread_info->index, "is died");
}
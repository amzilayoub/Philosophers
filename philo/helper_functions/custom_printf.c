# include "../include/philo.h"

int custom_printf(const char *str, t_thread_info *thread_info)
{
    struct timeval time_now;
    unsigned int time_in_milisec;

    pthread_mutex_lock(&thread_info->global_data->lock_stdin);
    time_in_milisec = get_time_now();
    if (!thread_info->global_data->philo_died)
        pthread_mutex_unlock(&thread_info->global_data->lock_stdin);
    return (printf("%u %d %s\n", time_in_milisec - g_process_starting_time, thread_info->index, str));
}
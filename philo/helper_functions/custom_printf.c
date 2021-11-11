# include "../include/philo.h"

int custom_printf(const char *str, t_thread_info *thread_info)
{
    struct timeval time_now;

    pthread_mutex_lock(&thread_info->global_data->lock_stdin);
    printf("%u %d %s\n", get_time_now() - g_process_starting_time, thread_info->index, str);
    // printf("-->> %d\n", thread_info->global_data->philo_died);
    // if (!thread_info->global_data->philo_died)
    pthread_mutex_unlock(&thread_info->global_data->lock_stdin);
    return (1);
}
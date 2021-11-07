# include "../include/philo.h"

int custom_printf(const char *str, t_thread_info *thread_info)
{
    struct timeval time_now;
    unsigned int time_in_milisec;

    pthread_mutex_lock(&thread_info->global_data->lock_stdin);
    gettimeofday(&time_now, NULL);
    time_in_milisec = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    pthread_mutex_unlock(&thread_info->global_data->lock_stdin);
    return (printf("%u %d %s\n", time_in_milisec, thread_info->index, str));
}
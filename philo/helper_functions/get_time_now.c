# include "../include/philo.h"

unsigned int get_time_now()
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    return (convert_to_milisec(time_now));
}
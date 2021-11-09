# include "../include/philo.h"


unsigned int convert_to_milisec(struct timeval time)
{
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
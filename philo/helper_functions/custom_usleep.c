# include "../include/philo.h"

void custom_usleep(useconds_t time_to_sleep)
{
    unsigned int start = get_time_now();
    usleep((time_to_sleep * 1e3) - 10000);
    while (get_time_now() - start < time_to_sleep)
        continue;
    
}
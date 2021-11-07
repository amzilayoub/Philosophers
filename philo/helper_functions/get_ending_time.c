# include "../include/philo.h"

void get_ending_time
(
    struct timeval starting_time,
    useconds_t time_to_add,
    struct timeval *ending_time
)
{
    // 1sec = 1 000 mil sec
    // 1sec = 1 000 000 micro sec
    // so 1 mil sec = 1000 micro sec
    // Convert to micro sec
    time_to_add *= 1000;
    ending_time->tv_sec = starting_time.tv_sec;
    ending_time->tv_usec = starting_time.tv_usec;
    ending_time->tv_sec += (time_t)(time_to_add / MAX_MICRO_SEC);
    time_to_add = (time_to_add % MAX_MICRO_SEC) + ending_time->tv_usec;
    ending_time->tv_sec += (time_t)(time_to_add / MAX_MICRO_SEC);
    ending_time->tv_usec = time_to_add % MAX_MICRO_SEC ;
}
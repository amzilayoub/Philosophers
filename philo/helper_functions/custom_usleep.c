# include "../include/philo.h"

void get_ending_time
(
    struct timeval starting_time,
    useconds_t time_to_sleep,
    struct timeval *ending_time
)
{
    // 1sec = 1 000 mil sec
    // 1sec = 1 000 000 micro sec
    // so 1 mil sec = 1000 micro sec
    // Convert to micro sec
    time_to_sleep *= 1000;
    ending_time->tv_sec = starting_time.tv_sec;
    ending_time->tv_usec = starting_time.tv_usec;
    ending_time->tv_sec += (time_t)(time_to_sleep / MAX_MICRO_SEC);
    time_to_sleep = (time_to_sleep % MAX_MICRO_SEC) + ending_time->tv_usec;
    ending_time->tv_sec += (time_t)(time_to_sleep / MAX_MICRO_SEC);
    ending_time->tv_usec = time_to_sleep % MAX_MICRO_SEC ;
}


void custom_usleep(useconds_t time_to_sleep)
{
    // starting time here: get_time
    // edning time = get_time + time_to_sleep

    /*
    while time_now < ending_time  {
        int factor = 2;
        sleep(time_to_sleep / factor);
        factor *= 2;
    }
    */
    struct timeval time_now;
    struct timeval ending_time;
    useconds_t tmp_sleep;
    int factor = 2;

    gettimeofday(&time_now, NULL);
    get_ending_time(time_now, time_to_sleep, &ending_time);
    while (1)
    {
        gettimeofday(&time_now, NULL);
        if (time_now.tv_sec > ending_time.tv_sec && time_now.tv_usec > ending_time.tv_usec)
            break;
        tmp_sleep = time_to_sleep / factor;
        if (tmp_sleep)
        {
            usleep(tmp_sleep);
            factor *= 2;
        }
    }
}
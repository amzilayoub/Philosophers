# include "../include/philo.h"

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
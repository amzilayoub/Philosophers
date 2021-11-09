# include "../include/philo.h"

// void custom_usleep(useconds_t time_to_sleep)
// {
//     // starting time here: get_time
//     // edning time = get_time + time_to_sleep

//     /*
//     while time_now < ending_time  {
//         int factor = 2;
//         sleep(time_to_sleep / factor);
//         factor *= 2;
//     }
//     */
//     unsigned int time_now;
//     unsigned int ending_time;
//     useconds_t tmp_sleep;
//     int factor = 2;

//     time_now = get_time_now();
//     ending_time = time_now + (time_to_sleep * 1000);
//     while (1)
//     {
//         time_now = get_time_now();
//         if (time_now >= ending_time)
//             break;
//         tmp_sleep = time_to_sleep / factor;
//         if (tmp_sleep)
//         {
//             usleep(tmp_sleep);
//             factor *= 2;
//         }
//     }
// }
// useconds_t get_current_time

void custom_usleep(useconds_t time_to_sleep)
{
    // unsigned int now;    
    // unsigned int end;
    // struct timeval time;

    // gettimeofday(&time, NULL);
    // now = convert_to_milisec(time);
    // end = now + time_to_sleep;
    // while (now <= end)
    // {
    //     gettimeofday(&time, NULL);
    //     now = convert_to_milisec(time);
    //     usleep(25);
    // }
    unsigned int end = get_time_now() + time_to_sleep;
    while (get_time_now() < end);
}
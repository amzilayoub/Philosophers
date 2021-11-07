#include "include/philo.h"

void watcher(t_data *data)
{
  int i;
  struct timeval time_now;
  struct timeval expected_time_to_die;

  while (1)
  {
    i = -1;
    while (++i < data->args->number_of_philosophers)
    {
      get_ending_time(data->threads_data[i].last_time_eat, data->args->time_to_die, &expected_time_to_die);
      gettimeofday(&time_now, NULL);
      if (time_now.tv_sec > expected_time_to_die.tv_sec && time_now.tv_usec > expected_time_to_die.tv_usec)
      {
        printf("%ld:%d\n%ld:%d\n", time_now.tv_sec, time_now.tv_usec, expected_time_to_die.tv_sec, expected_time_to_die.tv_usec);
        died(&data->threads_data[i]);
        exit(1);
      }
      
    }

  }
}

int main(int argc, char **argv)
{
  t_data *data;

  init(&data);
  if (parser(data->args, argc, argv))
  {
    // Error
  }
  fill_data(data);
  start_threads(data);
  watcher(data);
  return (0);
}
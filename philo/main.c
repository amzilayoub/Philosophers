#include "include/philo.h"

void watcher(t_data *data)
{
  int i;
  struct timeval time_now;
  unsigned long long last_time_eat;
  unsigned long long time_now_milisec;
  while (1)
  {
    i = -1;
    while (++i < data->args->number_of_philosophers)
    {
      gettimeofday(&time_now, NULL);
      last_time_eat = convert_to_milisec(data->threads_data[i].last_time_eat);
      time_now_milisec = convert_to_milisec(time_now);
      if (time_now_milisec - last_time_eat >= data->args->time_to_die)
      {
        printf("%llu\n%llu\n", time_now_milisec, last_time_eat);
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
  // sleep(5);
  return (0);
}
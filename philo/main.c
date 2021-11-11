#include "include/philo.h"

void watcher(t_data *data)
{
  int           i;
  int           min_eat_count;
  unsigned int  last_time_eat;
  unsigned int  time_now;
  while (1)
  {
    i = -1;
    min_eat_count = 0;
    while (++i < data->args->number_of_philosophers)
    {
      last_time_eat = data->threads_data[i].last_time_eat;
      time_now = get_time_now();
      if (time_now - last_time_eat >= data->args->time_to_die)
      {
        data->philo_died = TRUE;
        pthread_mutex_lock(&data->threads_data[i].is_eating);
        // printf("%u\n%u\n", time_now, last_time_eat);
        pthread_mutex_lock(&data->lock_stdin);
        died(&data->threads_data[i]);
        // pthread_mutex_unlock(&data->threads_data[i].is_eating);
        exit(1);
      }
      if (data->args->number_of_times_each_philosopher_must_eat <= data->threads_data[i].eat_count)
        min_eat_count += 1;
    }
    if (min_eat_count == data->args->number_of_philosophers && data->has_must_eat_count)
    {
      data->philo_died = TRUE;
      pthread_mutex_lock(&data->lock_stdin);
      printf("Simulation ends\n");
      exit(1);
    }
   //usleep(1e3);
  }
}

int main(int argc, char **argv)
{
  t_data *data;

  init(&data);
  if (parser(data, argc, argv))
  {
    // Error
  }
  fill_data(data);
  g_process_starting_time = get_time_now();
  start_threads(data);
  watcher(data);
  return (0);
}
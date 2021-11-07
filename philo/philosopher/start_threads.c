# include "../include/philo.h"

void start_threads(t_data *data)
{
  int i;
  void *thread_args;

  i = -1;
  while (++i < data->args->number_of_philosophers)
  {
    // thread_args
    pthread_create(&data->threads_data[i].thread_id, NULL, philo, (void*)&data->threads_data[i]);
  }
}
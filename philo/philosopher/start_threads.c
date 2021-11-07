# include "../include/philo.h"

void start_threads(t_data *data)
{
  int i;

  i = -1;
  while (++i < data->args->number_of_philosophers)
  {
    data->threads_data[i].global_data = data;
    pthread_create(&data->threads_data[i].thread_id, NULL, philo, (void*)&data->threads_data[i]);
  }
}
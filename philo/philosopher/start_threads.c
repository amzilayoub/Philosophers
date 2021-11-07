# include "../include/philo.h"

void start_threads(t_data *data)
{
  int i;
  t_thread_arg *args;

  i = -1;
  args = (t_thread_arg*)malloc(sizeof(t_thread_arg));
  while (++i < data->args->number_of_philosophers)
  {
    args->data = data;
    args->thread_info = &data->threads_data[i];
    // pthread_create(&data->threads_data[i].thread_id, NULL, philo, (void*)&data->threads_data[i]);
    pthread_create(&data->threads_data[i].thread_id, NULL, philo, (void*)args);
  }
}
# include "../include/philo.h"

void start_threads(t_data *data)
{
  int i;

  i = 1;
  while (i < data->args->number_of_philosophers)
  {
    data->threads_data[i].global_data = data;
    data->threads_data[i].eat_count = 0;
    data->threads_data[i].last_time_eat = get_time_now();
    pthread_create(&data->threads_data[i].thread_id, NULL, philo, (void*)&data->threads_data[i]);
    pthread_detach(data->threads_data[i].thread_id);
    i += 2;
  }
  usleep(100);
  i = 0;
  while (i < data->args->number_of_philosophers)
  {
    data->threads_data[i].global_data = data;
    data->threads_data[i].eat_count = 0;
    data->threads_data[i].last_time_eat = get_time_now();
    pthread_create(&data->threads_data[i].thread_id, NULL, philo, (void*)&data->threads_data[i]);
    pthread_detach(data->threads_data[i].thread_id);
    i += 2;
  }
}
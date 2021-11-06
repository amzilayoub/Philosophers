# include "include/philo.h"

void init(t_data **data)
{
  (*data) = (t_data*)malloc(sizeof(t_data));
  (*data)->args = (t_args*)malloc(sizeof(t_args));
}

void fill_data(t_data *data)
{
  int i;
  int next_philo_index;

  data->threads_data = (t_thread_info*)malloc(sizeof(t_thread_info) * data->args->number_of_philosophers);
  pthread_mutex_init(&data->stdin, NULL);
  i = -1;
  while (++i < data->args->number_of_philosophers)
  {
    data->threads_data[i].index = i + 1;
    pthread_mutex_init(&data->threads_data[i].fork, NULL);
    next_philo_index = (i + 1) % data->args->number_of_philosophers;
    data->threads_data[i].next_philo = &data->threads_data[next_philo_index];
  }
}
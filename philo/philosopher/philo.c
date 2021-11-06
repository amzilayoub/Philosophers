# include "../include/philo.h"

void lock_forks(t_thread_info *data)
{
  pthread_mutex_lock(&data->fork);
  pthread_mutex_lock(&data->next_philo->fork);
  printf("Locked -> %d - %d\n", data->index, data->next_philo->index);
}

void unlock_forks(t_thread_info *data)
{
  pthread_mutex_unlock(&data->fork);
  pthread_mutex_unlock(&data->next_philo->fork);
  printf("Unlocked -> %d - %d\n", data->index, data->next_philo->index);
}

void *philo(void *args)
{
  lock_forks((t_thread_info*)args);
  printf("Eating\n");
  unlock_forks((t_thread_info*)args);
  return NULL;
}
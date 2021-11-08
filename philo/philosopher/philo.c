# include "../include/philo.h"

void lock_forks(t_thread_info *thread_info)
{
  pthread_mutex_lock(&thread_info->fork);
  custom_printf("taken a fork", thread_info);
  pthread_mutex_lock(&thread_info->next_philo->fork);
  custom_printf("taken a fork", thread_info);
  // printf("\tLocked -> %d - %d\n", data->index, data->next_philo->index);
}

void unlock_forks(t_thread_info *thread_info)
{
  pthread_mutex_unlock(&thread_info->fork);
  pthread_mutex_unlock(&thread_info->next_philo->fork);
  // printf("\tUnlocked -> %d - %d\n", data->index, data->next_philo->index);
}

void *philo(void *args)
{
  t_thread_info *thread_info;

  thread_info = (t_thread_info*)args;
  if (!(thread_info->index % 2))
    usleep(100);
  while (1)
  {
    lock_forks(thread_info);
    eating(thread_info);
    sleeping(thread_info);
    thinking(thread_info);
  }
  return NULL;
}
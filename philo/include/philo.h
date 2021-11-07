# ifndef __PHILO_H__
#  define __PHILO_H__


/*
 * Defining the include
 */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define MAX_MICRO_SEC 1000000
/*
 * Defining the typedef/struct
 */

typedef struct  s_args {
  int number_of_philosophers;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int number_of_times_each_philosopher_must_eat;
}               t_args;

typedef struct s_thread_info {
  int             index;
  pthread_t       thread_id;
  pthread_mutex_t fork;
  struct s_thread_info *next_philo;
  struct timeval  last_time_eat;
  struct s_data   *global_data;
}               t_thread_info;

typedef struct  s_data {
  t_args          *args;
  t_thread_info   *threads_data;
  pthread_mutex_t lock_stdin;
}               t_data;


/*
 * Defining the functions
 */
int parser(t_args *args, int argc, char ** argv);
int		ft_atoi(const char *str);
void error();
void init(t_data **data);
void fill_data(t_data *data);
void *philo(void *args);
void start_threads(t_data *data);
void custom_usleep(useconds_t time_to_sleep);
void eating(t_thread_info *thread_info);
void sleeping(t_thread_info *thread_info);
void thinking(t_thread_info *thread_info);
int custom_printf(const char *str, t_thread_info *thread_info);
void get_ending_time
(
    struct timeval starting_time,
    useconds_t time_to_add,
    struct timeval *ending_time
);
void died(t_thread_info *thread_info);

#endif
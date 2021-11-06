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


/*
 * Defining the functions
 */
int parser(t_args *args, int argc, char ** argv);
int		ft_atoi(const char *str);
void error();
#endif
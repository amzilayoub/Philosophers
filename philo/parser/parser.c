# include "../include/philo.h"

void print_args(t_args *args)
{
  printf("number_of_philosophers = %d\n", args->number_of_philosophers);
  printf("time_to_die = %d\n", args->time_to_die);
  printf("time_to_eat = %d\n", args->time_to_eat);
  printf("time_to_sleep = %d\n", args->time_to_sleep);
  printf("number_of_times_each_philosopher_must_eat = %d\n", args->number_of_times_each_philosopher_must_eat);
}

int parser(t_args *args, int argc, char ** argv)
{
  if (argc < 5 || argc > 6)
    error();
  // NOTE: needs more checks to do
  args->number_of_philosophers = ft_atoi(argv[1]);
  args->time_to_die = ft_atoi(argv[2]);
  args->time_to_eat = ft_atoi(argv[3]);
  args->time_to_sleep = ft_atoi(argv[4]);
  if (argv[5])
    args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
  // print_args(args);
  return 0;
}
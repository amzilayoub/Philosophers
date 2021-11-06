#include "include/philo.h"

int main(int argc, char **argv)
{
  t_data *data = NULL;

  init(&data);
  if (parser(data->args, argc, argv))
  {
    // Error
  }
  fill_data(data);
  start_threads(data);
  sleep(10);
  return (0);
}
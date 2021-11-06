#include "include/philo.h"

int main(int argc, char **argv)
{
  t_args *args;

  args = (t_args*)malloc(sizeof(t_args));
  if (parser(args, argc, argv))
  {
    // Error
  }
  return (0);
}
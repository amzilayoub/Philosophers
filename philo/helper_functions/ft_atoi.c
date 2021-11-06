# include "../include/philo.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			res;
	long long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13 && str[i]) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (res < 0 && sign < 0)
			return (0);
		if (res < 0 && sign > 0)
			return (-1);
		res = (res * 10) + (str[i++] - '0');
	}
	return (res * sign);
}
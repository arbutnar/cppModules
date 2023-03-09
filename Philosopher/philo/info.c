#include "philo.h"

//void	ft_usleep(long long wait)
//{
//		long long start;
//	start = ft_time();
//	while (ft_time() < start + wait)
//		usleep (1000);
//}

void	ft_usleep(long long time)
{
	long long	tmp;

	tmp = ft_time();
	usleep(time * 1000 - 20000);
	while (ft_time() < tmp + time)
		continue ;
}

void	ft_display_info(t_philo *philo, char *str)
{
	long long time;

	time = ft_time() - philo->rules->start;
	if (ft_death_check(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->rules->msg_mtx);
	printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->rules->msg_mtx);
}

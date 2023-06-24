#include <pthread.h>
#include <stdio.h>


typedef pthread_mutex_t t_mutex;

struct t_data
{
	t_mutex	*mutex;
	int	*num;
}s_data;

void    *thread_routine(void *data)
{
	struct t_data	*_data = data;

	pthread_mutex_lock(_data->mutex);
	while ((*_data->num) < 10)
	{
		(*_data->num)++;
		pthread_mutex_unlock(_data->mutex);
		pthread_mutex_lock(_data->mutex);
	}
	pthread_mutex_unlock(_data->mutex);
    return (NULL);
}


int main()
{
	int	tmp = 0;
    pthread_t   thread1;
	t_mutex	mutex;

	struct	t_data	data;
	data.mutex = &mutex;
	data.num = &tmp;

	pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, thread_routine, &data);
	
	pthread_mutex_lock(&mutex);
	while (tmp < 10)
	{
		printf("%d\n", tmp++);
		pthread_mutex_unlock(&mutex);
		pthread_mutex_lock(&mutex);
	}
	pthread_mutex_unlock(&mutex);
	pthread_join(thread1, NULL);

    return (0);
}

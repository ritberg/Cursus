/*
Test :
Let's say that we want to count to 2.000.000
To do that with the multithreading we simply make
two threads that execute the same routine.
The routine increases the variable cont to 1.000.000
In this way we should execute this while loop 2 times
and when cont is printed we should get 2.000.000. 
*/

/*
   Here it dsn't work because of *data race*
   In other words, both threads tid1 and tid2
   access to the while loop and cont++
   but at different random time:
*/

#include <pthread.h>
#include <stdio.h>

int cont = 0;

void  *routine()
{
  int i;

  i = -1;
  while (++i < 1000000)
  	  cont++;
  return (NULL);
}

int main()
{
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("cont: %d\n", cont);
}


/*
   Here it works well and prints 2 000 000  
   thanks to mutex :
*/

#include <pthread.h>
#include <stdio.h>

int cont = 0;
pthread_mutex_t	mutex;

void  *routine()
{
	int i;
	
	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		cont++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main()
{
  pthread_t tid1, tid2;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_mutex_destroy(&mutex);
  printf("cont: %d\n", cont);
}


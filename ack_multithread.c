#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define THREADS 4

int ackermann(int m, int n)
{
        if (!m) return n + 1;
        if (!n) return ackermann(m - 1, 1);
        return ackermann(m - 1, ackermann(m, n - 1));
}

void* f(void* data) {
  printf("Hello from a thread!\n");
  pthread_exit(NULL);
}

int main()
{
        int m, n;
	pthread_t threads[THREADS];        
	
	clock_t tic = clock();
	
	int t;
  	for (t = 0; t < THREADS; t++) {
   		pthread_create(&threads[t], NULL, f, NULL);
	}


	for (m = 0; m <= 5; m++)
		for (n = 0; n < 6 - m; n++)
			printf("A(%d, %d) = %d\n", m, n, ackermann(m, n));
 
	clock_t toc = clock();
	
	double time_spent = (double) (toc - tic) / CLOCKS_PER_SEC;
	printf("Time spent computing was: %f seconds\n", time_spent);
        pthread_exit(NULL);
}

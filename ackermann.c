#include <stdio.h>
#include <time.h>

int ackermann(int m, int n)
{
        if (!m) return n + 1;
        if (!n) return ackermann(m - 1, 1);
        return ackermann(m - 1, ackermann(m, n - 1));
}
 
int main()
{
        int m, n;
        
	clock_t begin = clock();

	for (m = 0; m <= 6; m++)
                for (n = 0; n < 6 - m; n++)
                        printf("A(%d, %d) = %d\n", m, n, ackermann(m, n));
 
	clock_t end = clock();
	double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("Time spent computing was: %f\n", time_spent);
        return 0;
}

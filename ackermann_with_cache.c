/*Ackermann function makes a lot of recursive calls,
so the above program is a bit naive. We need to be slightly less naive, by doing some simple caching: 
Whee. Well, with some extra work, we calculated one more n value, big deal, right? But see, A(4, 2) = 
A(3, A(4, 1)) = A(3, 65533) = A(2, A(3, 65532)) = ... you can see how fast it blows up. In fact, no 
amount of caching will help you calculate large m values; on the machine I use A(4, 2) segfaults 
because the recursions run out of stack space--not a whole lot I can do about it. At least it runs 
out of stack space quickly, unlike the first solution... 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int m_bits, n_bits;
int *cache;
 
int ackermann(int m, int n)
{
        int idx, res;
        if (!m) return n + 1;
 
        if (n >= 1<<n_bits) {
                printf("%d, %d\n", m, n);
                idx = 0;
        } else {
                idx = (m << n_bits) + n;
                if (cache[idx]) return cache[idx];
        }
 
        if (!n) res = ackermann(m - 1, 1);
        else    res = ackermann(m - 1, ackermann(m, n - 1));
 
        if (idx) cache[idx] = res;
        return res;
}
int main()
{
        int m, n;
 
        m_bits = 3;
        n_bits = 20;  /* can save n values up to 2**20 - 1, that's 1 meg */
        cache = malloc(sizeof(int) * (1 << (m_bits + n_bits)));
        memset(cache, 0, sizeof(int) * (1 << (m_bits + n_bits)));
 
        for (m = 0; m <= 4; m++)
                for (n = 0; n < 6 - m; n++)
                        printf("A(%d, %d) = %d\n", m, n, ackermann(m, n));
 
        return 0;
}

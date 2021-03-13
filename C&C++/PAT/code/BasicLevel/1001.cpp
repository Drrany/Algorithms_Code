#include <cstdio>

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    while (n != 1)
    {
        count++;
        if (n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
    }
    printf("%d", count);
    return 0;
}
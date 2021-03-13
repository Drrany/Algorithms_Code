#include <cmath>
#include <iostream>
bool isPrim(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int count = 0, num = 2;
    int *ans = new int[n - m + 1];
    while (count < n)
    {
        if (isPrim(num))
        {
            // printf("%d ", num);
            count++;
            if (count >= m)
                ans[count - m] = num;
        }
        num++;
    }

    for (int i = 0; i < (n - m); i++)
    {
        printf("%d", ans[i]);
        (i % 10 == 9) ? printf("\n") : printf(" ");
    }
    printf("%d", ans[n - m]);
    return 0;
}
#include <cmath>
#include <cstdio>
int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int r = round(n / 2.0);
    for (int i = 0; i < n; i++)
        printf("%c", c);
    puts("");
    for (int i = 1; i < r - 1; i++)
    {
        printf("%c", c);
        for (int i = 1; i < n - 1; i++)
            printf(" ");
        printf("%c\n", c);
    }
    for (int i = 0; i < n; i++)
        printf("%c", c);
}
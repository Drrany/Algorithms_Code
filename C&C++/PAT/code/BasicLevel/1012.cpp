#include <cstdio>
using namespace std;
// 十进制->x进制
void convertToX(int x, int n)
{
    int ans[32];
    int len = 0;
    while (n > 0)
    {
        ans[len++] = n % x;
        n /= x;
    }
    for (int i = len - 1; i >= 0; i--)
        printf("%d", ans[i]);
}

int main()
{
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    convertToX(d, sum);
}
#include <main.c>

int reverse(int x)
{

    int ans = 0;

    while (x != 0)
    {

        int mod = x % 10;
        if (ans > (2147483647 / 10 - mod / 10) || ans < (-2147483648 / 10 - mod / 10))
            return 0;
        x /= 10;
        ans = ans * 10 + mod;
    }

    return ans;
}
#include <stdio.h>

int myAtoi(char *str)
{

    int n = 0;
    int ans = 0;

    while (str[n] != '\0' && str[n] == ' ')
        n++;

    if (str[n] == '\0' || !((str[n] <= '9' && str[n] >= '0') || (str[n] == '+' || str[n] == '-')))
        return 0;

    int flag = 1;
    if (str[n] == '-')
    {
        flag = -1;
        n++;
    }
    else if (str[n] == '+')
        n++;

    while (str[n] <= '9' && str[n] >= '0')
    {
        int t = str[n] - 48;
        if (flag == 1 && (ans > 214748364 || (ans == 214748364 && t >= 7)))
            return 2147483647;
        else if (flag == -1 && (ans > 214748364 || (ans == 214748364 && t >= 8)))
            return -2147483648;
        else
            ans = ans * 10 + t;
        n++;
    }

    return ans*flag;
}

int main()
{
    char c[] = "-2147483647";
    printf("%d", myAtoi(c));
}
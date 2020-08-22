#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x)
{

    if (x < 0)
        return false;

    int n[10] = {0};
    int i = 0;
    while (x != 0 && i <= 10)
    {
        n[i++] = x % 10;
        x /= 10;
    }

    for (int j = 0; j < i / 2; j++)
    {
        if (n[j] != n[i - 1 - j])
            return false;
    }
    return true;
}

int main()
{
    isPalindrome(2147483647);
}
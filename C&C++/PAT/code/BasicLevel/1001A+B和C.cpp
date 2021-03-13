#include <iostream>
#include <string>
using namespace std;
/* 
    溢出只会发生在a、b同号的情况下，因此当a、b同号时，
        若c与a、b同号，转换为a>c-b，c与-b是异号，必定不会出现溢出
        若c与a、b异号，根据c的正负即可判断大小关系
 */
int main()
{
    int n;
    long a, b, c;
    scanf("%d", &n);
    bool *ans = new bool[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%ld%ld%ld", &a, &b, &c);
        if (a == 0 || b == 0)
        {
            ans[i] = a + b > c;
            continue;
        }

        bool isPositive_a = a > 0;
        bool isPositive_b = b > 0;
        bool isPositive_c = c >= 0;

        if (isPositive_a == isPositive_b)
        {
            if (isPositive_b == isPositive_c)
                ans[i] = a > c - b;
            else
                ans[i] = c < 0;
        }
        else
            ans[i] = a + b > c;
    }

    for (int i = 0; i < n; i++)
    {
        string s = ans[i] ? "true" : "false";
        printf("Case #%d: %s\n", i + 1, s.c_str());
    }

    delete[] ans;
    return 0;
}
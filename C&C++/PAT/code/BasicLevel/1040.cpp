#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000007;
int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int pnum[len + 1];
    int tnum[len + 1];
    int ans = 0;
    pnum[0] = 0;
    tnum[len] = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'P')
            pnum[i + 1] = pnum[i] + 1;
        else
            pnum[i + 1] = pnum[i];
    }

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == 'T')
            tnum[i] = tnum[i + 1] + 1;
        else
            tnum[i] = tnum[i + 1];
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'A')
            ans = (ans + pnum[i + 1] * tnum[i + 1]) % MAX;
    }
    cout << ans;
}
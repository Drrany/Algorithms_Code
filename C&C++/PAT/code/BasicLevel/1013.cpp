#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000001;
bool notPrim[maxn] = {0};
int prim[maxn];

void findPrim(int n)
{
    int count = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (!notPrim[i])
        {
            prim[count++] = i;
            if (count >= n)
                break;
            for (int j = i * 2; j < maxn; j += i)
                notPrim[j] = true;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    findPrim(n);

    for (int j = m; j < n; j++)
    {
        cout << prim[j - 1];
        if ((j - m + 1) % 10 == 0)
            cout << endl;
        else
            cout << " ";
    }
    cout << prim[n - 1];
}
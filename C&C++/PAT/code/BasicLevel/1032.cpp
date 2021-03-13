#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 100001;
int main()
{
    int n;
    cin >> n;
    int sch[MAXSIZE];
    fill(sch, sch + MAXSIZE, 0);
    int ansId, ansScore = 0;
    for (int i = 0; i < n; ++i)
    {
        int index, s;
        cin >> index >> s;
        sch[index] += s;
        if (sch[index] > ansScore)
        {
            ansId = index;
            ansScore = sch[index];
        }
    }
    cout << ansId << " " << ansScore;
}
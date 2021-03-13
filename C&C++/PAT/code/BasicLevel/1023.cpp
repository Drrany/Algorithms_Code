#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    // 找到第一个非0的数输出
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] != 0)
        {
            cout << i;
            arr[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (arr[i] > 0)
        {
            cout << i;
            arr[i]--;
        }
    }
}
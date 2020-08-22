#include <iostream>
#include <math.h>
using namespace std;

int maxSum(int n, int m, int *arr)
{
    if (n < m || m < 1)
        return 0;
    int sum = 0;
    int tmp[m + 1][n + 1]; // tmp[i][j]表示数组的前j个元素中i个子段和的最大值

    for (int i = 0; i <= n; i++)
        tmp[0][i] = 0;
    for (int i = 0; i <= m; i++)
        tmp[i][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= n - m + i; j++)
        {
            if (j == i)
                tmp[i][j] = tmp[i - 1][j - 1] + arr[j]; // i等于j时，只需要将arr前j个元素相加
            else
            { // j大于i时
                tmp[i][j] = tmp[i][j - 1] + arr[j]; // 第i个子段和包括arr[j]
                for (int k = i - 1; k < j; k++) // 或者第i个子段和只包括arr[j]
                    tmp[i][j] = max(tmp[i][j], tmp[i - 1][k] + arr[j]);
            }
        }
    }
    for (int i = m; i <= n; i++)
        sum = max(sum, tmp[m][i]);

    return sum;
}

int main()
{
    cout << "hello";
}
#include <math.h>

using namespace std;

int maxSum(int n, int *arr)
{
    int sum = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp = max(tmp + arr[i], arr[i]);
        sum = max(tmp, sum);
    }
    return sum;
}

int maxSum2(int m, int n, int **arr)
{
    int sum = 0;
    int tmp[n];
    for (int i = 0; i < m; i++) // 从每行起始，考虑i~i+1行、i~i+2行、i~i+3行……的子矩阵
    {
        for (int k = 0; k < n; k++) // 初始化tmp数组
            tmp[k] = 0;

        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++) // tmp[k]表示第k列 i~j 行的元素相加
                tmp[k] += arr[j][k];

            sum = max(sum, maxSum(n, tmp)); // 将局部最优解和全局最优解相比较
        }
    }
    return sum;
}
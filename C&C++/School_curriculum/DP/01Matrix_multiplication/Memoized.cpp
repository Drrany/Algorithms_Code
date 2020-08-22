#include <iostream>
using namespace std;

/*
    p[]：矩阵维数
    n：矩阵个数
    m[][]：最优值数组
    s[][]：最优值断开位置数组
*/
int p[] = {30, 35, 15, 5, 10, 20, 25};
int n = 6;
int m[7][7];
int s[7][7];
int LookupChain(int i, int j)
{
    if (m[i][j] > 0) // 非特殊值直接返回结果
        return m[i][j];
    if (i == j)
        return 0;

    m[i][j] = 65535;
    for (int k = i; k < j; k++) // 计算每个插入点的数乘次数
    {
        int tmp = LookupChain(i, k) + LookupChain(k + 1, j) + p[i - 1] * p[k] * p[j];
        if (tmp < m[i][j])
        {
            m[i][j] = tmp;
            s[i][j] = k;
        }
    }
    return m[i][j];
}

int MemoizedMatrixChain()
{
    for (int i = 1; i <= n; i++) // 填入特殊值65535
        for (int j = 1; j <= n; j++)
            m[i][j] = 0;

    return LookupChain(1, n);
}
int main()
{
    int ans = MemoizedMatrixChain();
    cout << ans << endl;
}
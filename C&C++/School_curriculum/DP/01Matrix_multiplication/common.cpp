#include <iostream>
using namespace std;

/*
    p[]：矩阵维数
    n：矩阵个数
    m[][]：最优值数组
    s[][]：最优值断开位置数组
*/
void MatrixChain(int *p, int n, int m[][7], int s[][7])
{
    for (int i = 1; i <= n; i++) // 初始化m[i][i]
        m[i][i] = 0;

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 1; i <= n - gap; i++) // 计算m[i][i+gap]
        {
            int j = i + gap;

            m[i][j] = 65535;
            for (int k = i; k < j; k++) // 计算每个插入点的数乘次数
            {
                if ((m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]) < m[i][j])
                {
                    m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    s[i][j] = k;
                }
            }
        }
    }
}

void Traceback(int i, int j, int s[][7])
{
    if (i == j)
        return;
    Traceback(i, s[i][j], s);
    Traceback(s[i][j] + 1, j, s);

    cout << "Multiply A" << i << ", " << s[i][j];
    cout << " and A" << s[i][j] + 1 << ", " << j << endl;
}

int main()
{
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = 6;
    int m[7][7];
    int s[7][7];
    MatrixChain(p, n, m, s);
    // cout << m[1][6] << endl;
    // Traceback(1, 6, s);

    for (int i = 1; i < 7; i++)
    {
        for (int j = i; j < 7; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;

int LSCLength(int m, int n, char *x, char *y, int dp[][4], int sol[][4])
{
    for (int i = 0; i <= m; i++) // 定义 base case，dp[0][..] 和 dp[..][0] 初始化为 0
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                sol[i][j] = 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                sol[i][j] = 2;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                sol[i][j] = 3;
            }
        }
    }

    return dp[m][n];
}

int ilen = 0;
void getLSC(char *LSC, int i, int j, char *x, int sol[][4])
{
    if (i == 0 || j == 0)
        return;
    if (sol[i][j] == 1)
    {
        getLSC(LSC, i - 1, j - 1, x, sol);
        LSC[ilen++] = x[i - 1];
    }
    else if (sol[i][j] == 2)
        getLSC(LSC, i - 1, j, x, sol);
    else
        getLSC(LSC, i, j - 1, x, sol);
}

int main()
{
    char x[] = "abcde";
    char y[] = "ace";
    int dp[6][4];
    int sol[6][4];
    int len = LSCLength(5, 3, x, y, dp, sol);
    cout << len << endl;
    char LSC[len];
    getLSC(LSC, 5, 3, x, sol);
    for (int i = 0; i < len; i++)
    {
        cout << LSC[i];
    }
}
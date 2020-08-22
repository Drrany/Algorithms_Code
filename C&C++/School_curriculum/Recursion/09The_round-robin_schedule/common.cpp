#include <iostream>
#include <math.h>
using namespace std;

void Table(int k, int nums[][9])
{
    int n = pow(2, k);

    for (int i = 1; i <= n; i++)
        nums[1][i] = i;

    int m = 1;
    for (int s = 1; s <= k; s++) // 对于 2^k 个选手，需要填充 k 次
    {
        n /= 2;                      // 每填充一次，基本块的大小变大，数量变为原来一半
        for (int t = 1; t <= n; t++) // 对每个待填充的基本块
        {
            for (int i = m + 1; i <= 2 * m; i++) // i控制行数
            {
                for (int j = m + 1; j <= 2 * m; j++) // j控制列数
                {
                    nums[i][j + (t - 1) * m * 2] = nums[i - m][j + (t - 1) * m * 2 - m]; // 右下角的值等于左上角的值
                    nums[i][j + (t - 1) * m * 2 - m] = nums[i - m][j + (t - 1) * m * 2]; // 左下角的值等于右上角的值
                }
            }
        }
        m *= 2;
    }
}

int main()
{
    static int nums[9][9];
    Table(3, nums);

    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
            cout << nums[i][j] << "  ";
        cout << endl;
    }
}
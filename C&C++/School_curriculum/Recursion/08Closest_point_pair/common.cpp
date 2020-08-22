#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

// 点结构
struct pt
{
    double x, y;
    int id;
};

int len;
static const int MAXLEN = 10000;
pt set[MAXLEN];       // 初始点集
double minans = 1E20; // 最接近点对距离

bool cmp_x(pt p1, pt p2) { return p1.x < p2.x; }

bool cmp_y(const pt p1, const pt p2) { return p1.y < p2.y; }

inline void upd_ans(pt a, pt b) // 更新最近距离
{
    double dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    minans = dis < minans ? dis : minans;
}

void rec(int left, int right)
{
    if (right - left <= 2) // 当划分的子点集小于等于3个点时，直接计算最短距离
    {
        for (int i = left; i < right; i++)
        {
            for (int j = i + 1; j <= right; j++)
                upd_ans(set[i], set[j]);
        }
        sort(set + left, set + right + 1, cmp_y); // 将子点集内的点按y坐标大小排序
    }
    else // 当划分的子点集大于3个点时，分治
    {
        int m = (left + right) / 2; // 得到中位点下标
        int mx = set[m].x;          // 得到中位点的x坐标

        // 递归处理中位点左侧和右侧的点集
        rec(left, m);
        rec(m + 1, right);

        pt p1[len];
        pt p2[len];
        int len1 = 0, len2 = 0;
        for (int i = left; i <= m; i++) // 得到距离中点垂直线距离小于minans的左侧点集P1
        {
            if (abs(set[i].x - mx) < minans)
                p1[len1++] = set[i];
        }
        for (int i = m + 1; i <= right; i++) // 得到距离中点垂直线距离小于minans的右侧点集P2
        {
            if (abs(set[i].x - mx) < minans)
                p2[len2++] = set[i];
        }

        for (int i = 0; i < len1; i++) // 遍历P1
        {
            if ((p1[i].y - p2[0].y >= minans) || (len2 > 0 && (p2[len2 - 1].y - p1[i].y >= minans))) // 如果p1[i]点的右侧矩形中不存在p2点集中的点，则跳过遍历P2
                continue;
            for (int j = 0; j < len2; j++) // 遍历P2
            {
                if (abs(p1[i].y - p2[j].y) < minans) // 对于垂直方向距离小于minans的两点进行距离计算
                    upd_ans(p1[i], p2[j]);
            }
        }

        // 将两个子点集按照 y 坐标大小进行合并（因为两个内部已经按照y坐标排好序，所以只需要用merge合并）
        static pt tmp[MAXLEN];
        merge(set + left, set + m + 1, set + m + 1, set + right + 1, tmp, cmp_y);
        copy(tmp, tmp + right - left + 1, set + left);

        // // 将子点集按照y坐标排序，因为每个子点集内已经按y坐标排过，所以直接采用merge然后copy
        // static pt tmp[MAXLEN];
        // int size = right - left + 1;
        // merge(set + left, set + m + 1, set + m + 1, set + right + 1, tmp, cmp_y);
        // copy(tmp, tmp + right - left + 1, set + left);

        // // 遍历点集
        // for (int i = 0; i < size; i++)
        // {
        //     // 对于距离中位点x方向小于当前minans的点
        //     if (abs(tmp[i].x - mx) < minans)
        //     {
        //         // 计算其满足下列条件的点的距离：y方向距离其下（避免重复计算）；和其y方向的距离小于当前minans
        //         for (int j = i - 1; j >= 0 && ((tmp[i].y - tmp[j].y) < minans); j--)
        //             upd_ans(tmp[i], tmp[j]);
        //     }
        // }
    }
}

int main()
{
    cin >> len;

    for (int i = 0; i < len; i++)
        cin >> set[i].x >> set[i].y;

    sort(set, set + len, cmp_x); // 分治前将点根据x坐标排序
    rec(0, len - 1);

    // for (int i = 0; i < len; i++)
    //     cout << set[i].x << " " << set[i].y << endl;

    cout << minans;
}
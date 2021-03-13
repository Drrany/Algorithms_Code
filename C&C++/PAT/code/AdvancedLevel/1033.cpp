#include <bits/stdc++.h>
/* 重做
 * 遍历当前位置到能够到达的所有加油站，找出油价最低的那一个，
 *      如果该油价低于当前位置油价，就加刚好能到达那个加油站的距离的油
 *      如果该油价高于当前位置油价，就在当前加油站加满油之后过去。
 * */
using namespace std;

struct station {
    double price;
    double distance;
};

bool cmp(station a, station b) {
    return a.distance < b.distance;
}

int main() {
    int n;
    double d, c, avg;
    cin >> c >> d >> avg >> n;
    station *arr = new station[n + 1];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].price >> arr[i].distance;
    arr[n] = {0, d}; // 将终点看作价格为0，距离为d的加油站

    sort(arr, arr + n, cmp);
    if (arr[0].distance != 0) {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }

    int cur = 0;            // 当前所处加油站编号
    double oil = 0;         // 当前油量
    double maxRun = c * avg;   // 满油行驶距离
    double totalMoney = 0.0;// 总耗费
    while (cur < n) {
        // 在可到范围内先选择油价低于当前油价的且最近的
        int target = -1;
        double minPrice = -1;    // 最低油价
        for (int i = cur + 1; i <= n && maxRun + arr[cur].distance >= arr[i].distance; ++i) {
            if (minPrice < 0 || minPrice > arr[i].price) {  // 找最低油价
                minPrice = arr[i].price;
                target = i;
                if (minPrice < arr[cur].price) // 若找到的最低油价低于当前油价，直接跳出
                    break;
            }
        }
        if (target < 0) break; //找不到下一个加油站

        double needOil = (arr[target].distance - arr[cur].distance) / avg; // 从cur到index需要的油量
        if (minPrice < arr[cur].price) {
            if (oil >= needOil)
                oil -= needOil;
            else {
                totalMoney += (needOil - oil) * arr[cur].price;
                oil = 0;
            }
        } else { // 加满油离开
            totalMoney += (c - oil) * arr[cur].price;
            oil =c- needOil;
        }
        cur = target;
    }
    if (cur == n)
        printf("%.2f", totalMoney);
    else
        printf("The maximum travel distance = %.2f", arr[cur].distance + maxRun);
}
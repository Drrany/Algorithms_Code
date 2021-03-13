// 如何打素数表 复习
/*
 * 1. 分别枚举每个数，判断是否是素数，对于不超过10^5大小的数据没有问题，将素数存储在primeNum[]中
 * 2. 对于更大范围内的素数表建立，从2开始，若i是素数，筛去所有i的倍数
 * */
#include <bits/stdc++.h>

using namespace std;
vector<int> prime;

void getTable(vector<bool> &table, int maxn) { // 打一个质数表
    for (int i = 2; i < maxn; ++i) {
        if (table[i]) { // 若i是质数，将所有i的倍数置为非质数
            prime.push_back(i);
            int count = 2, res = i * 2;
            while (res < maxn) {
                table[res] = false;
                count++;
                res = count * i;
            }
        }
    }
}

struct node {
    int value, count;

    node(int v, int c) {
        value = v, count = c;
    }
};

int main() {
    int n;
    vector<node> ans;
    cin >> n;
    int maxn = sqrt(n) + 1;
    vector<bool> table(maxn, true); // table[i]=true说明i是质数
    getTable(table, maxn);

    cout << n << "=";
    int num = n, len = prime.size();
    for (int i = 0; i < len; ++i) {
        int count = 0;
        while (table[prime[i]] && n % prime[i] == 0) {
            count++;
            n /= prime[i];
        }
        if (count > 0) ans.emplace_back(prime[i], count);
    }
    len = ans.size();
    if (len == 0) cout << num;
    else {
        for (int i = 0; i < len; ++i) {
            cout << ans[i].value;
            if (ans[i].count > 1) cout << "^" << ans[i].count;
            if (i < len - 1) cout << "*";
        }
    }

}
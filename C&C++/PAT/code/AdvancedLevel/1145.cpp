#include <bits/stdc++.h>
/* 平方探测法：
 *      1. 插入时，index=base+(gap*gap)%Tsize gap取值：0~Tsize-1
 *      2. 查询时，index=base+(gap*gap)%Tsize gap取值：0~Tsize
 *          当table[index]==key或0时，查询结束，gap即为查询次数
 * */
using namespace std;
int table[10010]{};
int mSize;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool insertKey(int num) {
    for (int i = 0; i <= mSize; ++i) {
        int tg = (num % mSize + (int) pow(i, 2)) % mSize;
        if (table[tg] == 0) {
            table[tg] = num;
            return true;
        }
    }
    return false;
}

int findKey(int num) {
    int i = 0;
    for (; i < mSize; ++i) {
        int tg = (num % mSize + (int) pow(i, 2)) % mSize;
        if (table[tg] == num || table[tg] == 0) break;
    }
    return i + 1;
}

int main() {
    int n, m, key;
    cin >> mSize >> n >> m;
    while (!isPrime(mSize)) mSize++;
    for (int i = 0; i < n; ++i) {
        cin >> key;
        if (!insertKey(key)) cout << key << " cannot be inserted.\n";
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> key;
        ans += findKey(key);
    }
    printf("%.1f", (double) ans / (double) m);
}
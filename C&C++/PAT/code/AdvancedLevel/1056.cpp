#include <bits/stdc++.h>
// 没有晋级的老鼠排名就是group+1
using namespace std;
struct info {
    int weight;
    int id;
    int order;
    int rank;
};

bool cmp1(const info &a, const info &b) {
    return a.order < b.order;
}

bool cmp2(const info &a, const info &b) {
    return a.id < b.id;
}

int main() {
    int np, ng, ord;
    cin >> np >> ng;
    vector<info> arr(np);
    vector<int> tops;
    for (int i = 0; i < np; ++i) {
        cin >> arr[i].weight;
        arr[i].id = i;
        tops.push_back(i);
    }
    for (int i = 0; i < np; ++i) {
        cin >> ord;
        arr[ord].order = i;
    }

    // 根据入场顺序排队
    sort(arr.begin(), arr.end(), cmp1);
    vector<int> next;
    while (true) {
        // 在tops中每ng人分为一组
        int len = tops.size(), rank = ceil((double)len / ng) + 1, i = 0, j;
        while (i < len) {
            j = min(len, i + ng);
            int tg = tops[i], maxWei = arr[tops[i]].weight;
            for (int k = i; k < j; ++k) {
                arr[tops[k]].rank = rank;
                if (arr[tops[k]].weight > maxWei) {
                    maxWei = arr[tops[k]].weight;
                    tg = tops[k];
                }
            }
            next.push_back(tg);
            i += ng;
        }
        tops = next;
        next.clear();
        if (tops.size() == 1) {
            arr[tops[0]].rank = 1;
            break;
        }
    }


    sort(arr.begin(), arr.end(), cmp2);
    for (int i = 0; i < np; ++i) {
        cout << arr[i].rank;
        if (i < np - 1) cout << " ";
    }

}

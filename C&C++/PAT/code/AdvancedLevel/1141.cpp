/* 
transform(str.begin(), str.end(), str.begin(), ::tolower)
四个输入参数
    1. str.begin()字符串的起始地址；
    2. str.end()字符串的终止地址；
    3. str.begin()是转换之后，输出到原str字符串的起始地址；
    4. 转换操作，可以选择toupper，tolower。
 */

#include <bits/stdc++.h>

using namespace std;

struct Inst {
    string sch;
    int rank, num = 0, intSum = 0;
    double total = 0;

    Inst(const string &s) {
        sch = s;
    }
};

bool cmp(const Inst &a, const Inst &b) {
    if (a.intSum != b.intSum) return a.intSum > b.intSum;
    if (a.num != b.num) return a.num < b.num;
    return a.sch < b.sch;
}

int main() {
    int n, len = 0;
    string id, sch;
    double score;
    map<string, int> schMp;
    vector<Inst> arr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> score >> sch;
        transform(sch.begin(), sch.end(), sch.begin(), ::tolower);
        if (schMp.find(sch) == schMp.end()) {
            schMp[sch] = len++;
            arr.emplace_back(sch);
        }
        int index = schMp[sch];
        (arr[index].num)++;
        if (id[0] == 'B')
            arr[index].total += score / 1.5;
        else if (id[0] == 'A')
            arr[index].total += score;
        else arr[index].total += score * 1.5;
        arr[index].intSum = (int) (arr[index].total);
    }

    sort(arr.begin(), arr.end(), cmp);
    arr[0].rank = 1;
    cout << len << endl;
    for (int i = 1; i < len; ++i) {
        // cout << arr[i].total << " " << arr[i - 1].total << endl;
        if (arr[i].intSum == arr[i - 1].intSum)
            arr[i].rank = arr[i - 1].rank;
        else arr[i].rank = i + 1;
    }
    for (int i = 0; i < len; ++i)
        cout << arr[i].rank << " " << arr[i].sch << " " << arr[i].intSum << " " << arr[i].num << endl;


}
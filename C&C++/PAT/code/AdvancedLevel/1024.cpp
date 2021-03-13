#include <bits/stdc++.h>

using namespace std;

bool isPalindromic(const string &str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j]) return false;
        else i++, j--;
    }
    return true;
}

string getRes(const string &str) {
    string res, rev = str;
    reverse(rev.begin(), rev.end());
    // 将rev和str相加
    int carry = 0, sum;
    for (int i = str.size() - 1; i >= 0; --i) {
        sum = str[i] - '0' + rev[i] - '0' + carry;
        carry = sum / 10;
        res.insert(0, 1, (char) (sum % 10 + '0'));
    }
    if (carry > 0) res.insert(0, 1, '1');
    return res;
}

int main() {
    string ori;
    int steps, i = 0;
    cin >> ori >> steps;
    while (!isPalindromic(ori) && i < steps) {
        ori = getRes(ori);
        i++;
    }
    cout << ori << "\n" << i;
}
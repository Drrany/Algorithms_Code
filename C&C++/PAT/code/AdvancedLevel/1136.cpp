#include <bits/stdc++.h>

using namespace std;

bool isPalindromic(const string &str) {
    int len = str.size();
    int i = 0, j = len - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

string addNum(const string &str1, const string &str2) {
    string sum;
    int len1 = str1.size(), len2 = str2.size(), a, b, tmp, carry = 0;
    for (int i = 0; i < len1 || i < len2; ++i) {
        a = (i < len1) ? (str1[i] - '0') : 0;
        b = (i < len2) ? (str2[i] - '0') : 0;
        tmp = a + b + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        sum.insert(0, 1, (char) tmp + '0');
    }
    if (carry != 0) sum.insert(0, 1, '1');
    return sum;
}

int main() {
    string ori, rev;
    cin >> ori;
    for (int i = 0; i < 10; ++i) {
        if (isPalindromic(ori)) {
            cout << ori << " is a palindromic number.";
            return 0;
        }
        rev = ori;
        reverse(rev.begin(), rev.end());
        cout << ori << " + " << rev << " = ";
        ori = addNum(ori, rev);
        cout << ori << endl;
    }

    cout << "Not found in 10 iterations.";
}
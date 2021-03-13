#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    string num;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        int dotNum = 0;       // 小数点个数
        bool isNum = true;    // 是否含有非数字
        int fracNum = 0;      // 小数点部分
        for (int j = 0; j < num.size(); ++j) {
            if (j == 0 && num[j] == '-') continue;
            if (num[j] == '.') dotNum++;
            else if (!(num[j] <= '9' && num[j] >= '0')) isNum = false;
            else if (dotNum > 0) fracNum++;
        }
        if (isNum && dotNum <= 1 && fracNum <= 2) {
            double tmp = stod(num);
            if (tmp >= -1000 && tmp <= 1000) {
                count++;
                sum += tmp;
                continue;
            }
        }
        cout << "ERROR: " << num << " is not a legal number\n";
    }
    if (count == 0) cout << "The average of 0 numbers is Undefined";
    else if (count == 1) printf("The average of 1 number is %.2f", sum / count);
    else printf("The average of %d numbers is %.2f", count, sum / count);
}













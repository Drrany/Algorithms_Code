#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    string str;
    int a, b, c;
    int flag;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        flag = 0;
        a = 0, b = 0, c = 0;
        int len = str.size();
        bool valid = true;
        for (int j = 0; j < len && valid; ++j) {
            if (flag == 0) {
                if (str[j] == 'A')
                    a++;
                else if (str[j] == 'P')
                    flag = 1;
                else
                    valid = false;
            } else if (flag == 1) {
                if (str[j] == 'A')
                    b++;
                else if (str[j] == 'T' && b > 0)
                    flag = 2;
                else valid = false;
            } else if (flag == 2) {
                if (str[j] == 'A')
                    c++;
                else valid = false;
            }
        }
        if (flag == 2 && valid && a * b == c)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}
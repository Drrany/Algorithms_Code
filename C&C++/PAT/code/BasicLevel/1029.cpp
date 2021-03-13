#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int i = 0, j = 0;
    int wrong[37]{};
    int len1 = str1.size(), len2 = str2.size();
    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            int index;
            if (str1[i] >= 'A' && str1[i] <= 'Z') {
                index = str1[i] - 'A';
                if (wrong[index] == 0) {
                    wrong[index]++;
                    cout << str1[i];
                }
            } else if (str1[i] >= 'a' && str1[i] <= 'z') {
                index = str1[i] - 'a';
                if (wrong[index] == 0) {
                    wrong[index]++;
                    char newc = char(str1[i] - ('a' - 'A'));
                    cout << newc;
                }
            } else if (str1[i] >= '0' && str1[i] <= '9') {
                index = str1[i] - '0' + 26;
                if (wrong[index] == 0) {
                    wrong[index]++;
                    cout << str1[i];
                }
            } else if (wrong[36] == 0) {
                wrong[36]++;
                cout << "_";
            }
            i++;
        } else {
            i++;
            j++;
        }
    }

    while (i < len1) {
        int index;
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            index = str1[i] - 'A';
            if (wrong[index] == 0) {
                wrong[index]++;
                cout << str1[i];
            }
        } else if (str1[i] >= 'a' && str1[i] <= 'z') {
            index = str1[i] - 'a';
            if (wrong[index] == 0) {
                wrong[index]++;
                char newc = char(str1[i] - ('a' - 'A'));
                cout << newc;
            }
        } else if (str1[i] >= '0' && str1[i] <= '9') {
            index = str1[i] - '0' + 26;
            if (wrong[index] == 0) {
                wrong[index]++;
                cout << str1[i];
            }
        } else if (wrong[36] == 0) {
            wrong[36]++;
            cout << "_";
        }
        i++;
    }


}
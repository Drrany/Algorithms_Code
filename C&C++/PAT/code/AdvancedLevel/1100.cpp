#include <bits/stdc++.h>

using namespace std;

int main() {
    string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string high[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    map<string, int> lowDigit = {
            {"tret", 0},
            {"jan",  1},
            {"feb",  2},
            {"mar",  3},
            {"apr",  4},
            {"may",  5},
            {"jun",  6},
            {"jly",  7},
            {"aug",  8},
            {"sep",  9},
            {"oct",  10},
            {"nov",  11},
            {"dec",  12}
    };
    map<string, int> highDigit = {
            {"tret", 0},
            {"tam",  1},
            {"hel",  2},
            {"maa",  3},
            {"huh",  4},
            {"tou",  5},
            {"kes",  6},
            {"hei",  7},
            {"elo",  8},
            {"syy",  9},
            {"lok",  10},
            {"mer",  11},
            {"jou",  12}
    };

    string str;
    getline(cin, str);
    int n = stoi(str);
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if (isdigit(str[0])) { // 10进制转13进制
            int num = stoi(str);
            if (num < 13)
                str = low[num];
            else {
                str = high[num / 13];
                if (num % 13 != 0)
                    str += " " + low[num % 13];
            }
            cout << str << endl;
        } else { // 13进制转10进制
            string h, l;
            int t1 = 0, t2 = 0;
            h = str.substr(0, 3);
            if (str.size() > 4) l = str.substr(4, 3);
            if (highDigit.find(h) != highDigit.end())
                t1 = highDigit[h];
            if (lowDigit.find(h) != lowDigit.end())
                t2 = lowDigit[h];
            if (lowDigit.find(l) != lowDigit.end())
                t2 = lowDigit[l];
            cout << t1 * 13 + t2 << endl;
        }
    }
}
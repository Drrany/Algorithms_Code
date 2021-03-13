#include <bits/stdc++.h>

using namespace std;

int toSec(const string &str) {
    int sec = 0;
    sec += stoi(str.substr(0, 2)) * 3600;
    sec += stoi(str.substr(3, 2)) * 60;
    sec += stoi(str.substr(6, 2));
    return sec;
}

int main() {
    int m;
    cin >> m;
    int in = INT32_MAX, out = 0, tin, tout;
    string ansIn, ansOut, id, inTime, outTime;
    for (int i = 0; i < m; ++i) {
        cin >> id >> inTime >> outTime;
        tin = toSec(inTime);
        tout = toSec(outTime);
        if (tin < in) {
            in = tin;
            ansIn = id;
        }
        if (tout > out) {
            out = tout;
            ansOut = id;
        }
    }
    cout << ansIn << " " << ansOut;

}
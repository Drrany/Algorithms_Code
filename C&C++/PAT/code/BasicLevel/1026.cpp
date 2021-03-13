#include <bits/stdc++.h>

using namespace std;

// 直接用c的printf格式化输出更简单

string deal(int sec)
{
    string hh, mm, ss;
    int hour, minute;

    hour = sec / (60 * 60);
    if (hour != 0)
        sec -= hour * 60 * 60;
    minute = sec / 60;
    if (minute != 0)
        sec -= minute * 60;

    hh = to_string(hour);
    mm = to_string(minute);
    ss = to_string(sec);

    hh.insert(0, 2 - hh.size(), '0');
    mm.insert(0, 2 - mm.size(), '0');
    ss.insert(0, 2 - ss.size(), '0');

    string res = hh + ':' + mm + ':' + ss;
    return res;
}

int main()
{
    int c1, c2;
    cin >> c1 >> c2;
    int sub = c2 - c1;
    int sec = round(double(sub) / 100.0);
    string res = deal(sec);
    cout << res;
}
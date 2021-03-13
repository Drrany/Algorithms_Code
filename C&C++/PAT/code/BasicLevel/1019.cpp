#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

string myminus(string a, string b)
{
    string res;
    int na = stoi(a);
    int nb = stoi(b);
    int nr = na - nb;
    if (nr == 0)
        res = "0000";
    else
    {
        while (nr > 0)
        {
            char c = (nr % 10) + '0';
            nr /= 10;
            res.insert(0, 1, c);
        }
        res.insert(0, 4 - res.size(), '0');
    }

    return res;
}

int main()
{
    string num;
    cin >> num;
    num.insert(0, 4 - num.size(), '0');
    string a, b, c;
    sort(num.begin(), num.end(), cmp); // 递减排序
    while (num != "6174" && num != "0000")
    {
        sort(num.begin(), num.end(), cmp); // 递减排序
        a = num;
        sort(num.begin(), num.end()); // 递增排序
        b = num;
        c = myminus(a, b);
        cout << a << " - " << b << " = " << c << endl;
        num = c;
    }
}
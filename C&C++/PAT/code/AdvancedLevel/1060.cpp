#include <bits/stdc++.h>
using namespace std;

int n; // 有效位数
string deal(string str, int &exp)
{
    string res;
    int count = 0;
    // 去掉str的前导零
    while (str.size() > 0 && str[0] == '0')
        str.erase(str.begin());
    if (str[0] == '.')
    { // str小于1
        str.erase(str.begin());
        while (str.length() > 0 && str[0] == '0')
        {
            str.erase(str.begin());
            exp--;
        }
    }
    else
    {
        while (str.length() > count && str[count] != '.')
        {
            count++;
            exp++;
        }
        if (count < str.length())           // 碰到小数点
            str.erase(str.begin() + count); // 删除小数点
    }
    if (str.length() == 0) // str是0
        exp = 0;
    int num = 0;
    count = 0;
    while (num < n)
    {
        if (count < str.length())
            res += str[count++];
        else
            res += '0';
        num++;
    }

    return res;
}
int main()
{
    string str1, str2;
    int exp1 = 0, exp2 = 0;
    cin >> n >> str1 >> str2;
    string str3 = deal(str1, exp1);
    string str4 = deal(str2, exp2);
    if (str3 == str4 && exp1 == exp2)
        cout << "YES 0." << str3 << "*10^" << exp1 << endl;
    else
        cout << "NO 0." << str3 << "*10^" << exp1 << " 0." << str4 << "*10^" << exp2 << endl;
    return 0;
}


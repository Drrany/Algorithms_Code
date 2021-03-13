// unordered_map/set的输出顺序并不是添加顺序

#include <bits/stdc++.h>

using namespace std;

int fine[129]{};
int broke[129]{};

int main()
{
    int k;
    cin >> k;
    string str;
    cin >> str;
    vector<int> bs;
    int i = 0, j = 0, len = str.size();
    while (i < len)
    {
        while (j < len && str[i] == str[j])
            j++;
        if ((j - i) % k != 0)
            fine[str[i]] = 1;
        else
        {
            broke[str[i]] = -1;
            bs.push_back(str[i]);
        }
        i = j;
    }

    // 在broke中去掉可能是fine的字符
    for (int l = 0; l < 129; ++l)
    {
        if (broke[l] == -1 && fine[l] == 1)
            broke[l] = 0;
    }

    unordered_set<char> output;
    for (const auto &e : bs)
    {
        if ((broke[e] == -1) && output.find(e) == output.end())
        {
            cout << (char)e;
            output.insert(e);
        }
    }
    cout << endl;
    for (int l = 0; l < len; ++l)
    {
        cout << str[l];
        if (broke[str[l]] == -1)
            l += k - 1;
    }
}
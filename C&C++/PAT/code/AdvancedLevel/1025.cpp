#include <bits/stdc++.h>
using namespace std;
typedef struct student
{
    string reg;
    int final_rank;
    int loc_num;
    int loc_rank;
    int score;
} stu;

bool cmp(stu s1, stu s2)
{
    if (s1.score == s2.score)
        return s1.reg < s2.reg;
    return s1.score > s2.score;
}

int main()
{
    int loc_total;
    cin >> loc_total;
    vector<stu> all;
    for (int i = 1; i <= loc_total; i++)
    {
        int num;
        cin >> num;
        int offset = all.size();
        for (int j = 0; j < num; j++)
        {
            stu s;
            cin >> s.reg;
            cin >> s.score;
            s.loc_num = i;
            all.push_back(s);
        }
        sort(all.begin() + offset, all.end(), cmp);
        all[offset].loc_rank = 1;
        for (int j = offset + 1; j < all.size(); j++)
        {
            if (all[j].score == all[j - 1].score)
                all[j].loc_rank = all[j - 1].loc_rank;
            else
                all[j].loc_rank = j + 1 - offset;
        }
    }

    sort(all.begin(), all.end(), cmp);
    int total_num = all.size();
    cout << total_num << endl;
    all[0].final_rank = 1;
    cout << all[0].reg << " " << all[0].final_rank << " " << all[0].loc_num << " " << all[0].loc_rank << endl;
    for (int i = 1; i < total_num; i++)
    {
        if (all[i].score == all[i - 1].score)
            all[i].final_rank = all[i - 1].final_rank;
        else
            all[i].final_rank = i + 1;
        cout << all[i].reg << " " << all[i].final_rank << " " << all[i].loc_num << " " << all[i].loc_rank << endl;
    }
}
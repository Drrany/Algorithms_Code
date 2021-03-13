#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int len = str.size();
    char ans[81];
    int i = 0;
    int left = len - 1, right = len;
    while (left >= 0)
    {
        while (left >= 0 && str[left] != ' ')
            left--;
        for (int k = left + 1; k < right; k++)
            ans[i++] = str[k];
        if (left >= 0)
            ans[i++] = ' ';
        right = left;
        left--;
    }
    ans[i++] = '\0';
    puts(ans);
}
// int main()
// {
//     char str[80], c;
//     int i = 0;
//     while ((c = getchar()) != '\n')
//         str[i++] = c;

//     char ans[i + 1];
//     int left = i - 1, right = i, n = 0;
//     while (left >= 0)
//     {
//         while (str[left] != ' ' && left >= 0)
//             left--;
//         int j = 1;
//         while ((left + j) < right)
//             ans[n++] = str[left + (j++)];
//         ans[n++] = ' ';
//         right = left--;
//     }
//     ans[n - 1] = '\0';
//     puts(ans);
//     return 0;
// }


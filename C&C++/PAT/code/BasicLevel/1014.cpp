#include <iostream>
#include <string>
using namespace std;

string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
string hour[] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"};
int main()
{
    string a, b, c, d;
    a.resize(60);
    b.resize(60);
    c.resize(60);
    d.resize(60);
    scanf("%s", &a[0]);
    scanf("%s", &b[0]);
    scanf("%s", &c[0]);
    scanf("%s", &d[0]);

    int i = 0;
    int count = 0;
    string ans;
    while (a.size() > i && b.size() > i)
    {
        if (a[i] == b[i])
        {
            if (count == 0 && (a[i] >= 'A' && a[i] <= 'G'))
            {
                ans += week[a[i] - 'A'] + ' ';
                count++;
            }
            else if (count == 1 && ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N')))
            {
                if (a[i] >= '0' && a[i] <= '9')
                    ans += hour[a[i] - '0'] + ':';
                else
                    ans += hour[a[i] - 'A' + 10] + ':';
                break;
            }
        }
        i++;
    }
    i = 0;
    while (c.size() > i && d.size() > i)
    {
        if ((c[i] == d[i]) && ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')))
            break;
        i++;
    }

    char low = '0' + i % 10;
    char high = '0' + i / 10;

    ans += high;
    ans += low;
    printf("%s", ans.c_str());
}
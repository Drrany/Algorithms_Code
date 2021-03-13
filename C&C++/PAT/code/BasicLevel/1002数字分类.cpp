#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    int n4 = 0;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        int r = a % 5;
        switch (r)
        {
        case 0: if (a % 2 == 0) a1 += a;
                break;
        case 1:
            a2 += flag * a;
            flag = -flag;
            break;
        case 2:
            a3++;
            break;
        case 3:
            n4++;
            a4 += a;
            break;
        case 4:
            a5 = max(a5, a);
            break;
        }
    }
    (a1 != 0) ? printf("%d ", a1) : printf("N ");
    (a2 != 0) ? printf("%d ", a2) : printf("N ");
    (a3 != 0) ? printf("%d ", a3) : printf("N ");
    (a4 != 0) ? printf("%.1f ", ((float)a4 / n4)) : printf("N ");
    (a5 != 0) ? printf("%d", a5) : printf("N");
}

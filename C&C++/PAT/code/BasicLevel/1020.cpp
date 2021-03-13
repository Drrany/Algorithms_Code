#include <bits/stdc++.h>
using namespace std;

typedef struct mooncake
{
    double weight;
    double price;
    double total;
} mc;
mc arr[1001];
bool cmp(mc m1, mc m2)
{
    return m1.price > m2.price;
}
int main()
{
    int n;
    double c;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
        cin >> arr[i].weight;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].total;
        arr[i].price = arr[i].total / arr[i].weight;
    }
    sort(arr, arr + n, cmp);
    double maxpro = 0;
    int i = 0;
    while (c > 0 && i < n)
    {
        if (c >= arr[i].weight)
        {
            maxpro += arr[i].total;
            c -= arr[i].weight;
        }
        else
        {
            maxpro += c * arr[i].price;
            break;
        }
        i++;
    }
    cout << fixed << setprecision(2) << maxpro;
}
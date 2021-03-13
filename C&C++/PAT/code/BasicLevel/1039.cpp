#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int hm1[128]{};
    int hm2[128]{};
    for (int i = 0; i < str1.size(); ++i)
        hm1[str1[i]]++;
    for (int i = 0; i < str2.size(); ++i)
        hm2[str2[i]]++;
    int rest = 0, lack = 0;
    bool canBuy = true;
    for (int i = 0; i < 128; ++i) {
        if (hm1[i] >= hm2[i])
            rest += hm1[i] - hm2[i];
        else {
            canBuy = false;
            lack += hm2[i] - hm1[i];
        }
    }
    if (canBuy)
        cout << "Yes " << rest;
    else cout << "No " << lack;


}
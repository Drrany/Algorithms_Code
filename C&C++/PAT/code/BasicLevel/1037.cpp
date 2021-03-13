#include <bits/stdc++.h>

using namespace std;

struct money {
    int g;
    int s;
    int k;
};

bool isGt(money a, money b) {
    if (a.g > b.g)
        return true;
    else if (a.g == b.g && a.s > b.s)
        return true;
    else if (a.g == b.g && a.s == b.s && a.k >= b.k)
        return true;
    return false;
}

money minusM(money a, money b) {
    money res = {0, 0, 0};

    res.k = a.k - b.k;
    if (res.k < 0) {
        res.k += 29;
        a.s--;
    }
    res.s = a.s - b.s;
    if (res.s < 0) {
        res.s += 17;
        a.g--;
    }
    res.g = a.g - b.g;
    return res;
}


int main() {
    money p, a, res;
    scanf("%d.%d.%d %d.%d.%d", &p.g, &p.s, &p.k, &a.g, &a.s, &a.k);
    if (isGt(a, p))
        res = minusM(a, p);
    else {
        cout << "-";
        res = minusM(p, a);
    }
    cout << res.g << "." << res.s << "." << res.k;
}
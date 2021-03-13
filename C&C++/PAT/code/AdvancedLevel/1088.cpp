#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 最大公约数
ll getGCD(ll a, ll b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

// 最小公倍数
ll getLCM(ll a, ll b) {
    if (a > b) return a / getGCD(a, b) * b;
    return a / getGCD(b, a) * b;
}

void formatPrint(ll fz, ll fm) {
    if (fm < 0) {
        fz = -fz;
        fm = -fm;
    }
    if (fz == 0) fm = 1;
    else {
        int gcd = getGCD(abs(fm), abs(fz));
        fm /= gcd;
        fz /= gcd;
    }

    if (fz < 0) cout << "(";

    if (fm == 1) cout << fz; // 整数
    else if (abs(fz) >= fm) // 假分数
        cout << fz / fm << " " << abs(fz) % fm << "/" << fm;
    else cout << fz << "/" << fm; // 真分数

    if (fz < 0) cout << ")";
}

void allPrint(string op, ll fz1, ll fm1, ll fz2, ll fm2) {
    formatPrint(fz1, fm1);
    cout << " " << op << " ";
    formatPrint(fz2, fm2);
    cout << " = ";
}

void divide(ll fz1, ll fm1, ll fz2, ll fm2) {
    allPrint("/", fz1, fm1, fz2, fm2);
    if (fz2 == 0) {
        cout << "Inf" << endl;
        return;
    }
    ll fzSum, fmSum;
    fzSum = fz1 * fm2;
    fmSum = fm1 * fz2;
    formatPrint(fzSum, fmSum);
    cout << endl;
}

void multi(ll fz1, ll fm1, ll fz2, ll fm2) {
    allPrint("*", fz1, fm1, fz2, fm2);
    ll fzSum, fmSum;
    fzSum = fz1 * fz2;
    fmSum = fm1 * fm2;
    formatPrint(fzSum, fmSum);

    cout << endl;
}

void minusRation(ll fz1, ll fm1, ll fz2, ll fm2) {
    allPrint("-", fz1, fm1, fz2, fm2);
    ll fzSum, fmSum;
    fmSum = getLCM(fm1, fm2);
    fz1 *= fmSum / fm1;
    fz2 *= fmSum / fm2;
    fzSum = fz1 - fz2;
    formatPrint(fzSum, fmSum);

    cout << endl;
}

void add(ll fz1, ll fm1, ll fz2, ll fm2) {
    allPrint("+", fz1, fm1, fz2, fm2);
    ll fzSum, fmSum;
    fmSum = getLCM(fm1, fm2);
    fz1 *= fmSum / fm1;
    fz2 *= fmSum / fm2;
    fzSum = fz1 + fz2;
    formatPrint(fzSum, fmSum);

    cout << endl;
}

int main() {
    ll fz1, fm1, fz2, fm2;
    scanf("%lld/%lld %lld/%lld", &fz1, &fm1, &fz2, &fm2);
    add(fz1, fm1, fz2, fm2);
    minusRation(fz1, fm1, fz2, fm2);
    multi(fz1, fm1, fz2, fm2);
    divide(fz1, fm1, fz2, fm2);
}
#include <bits/stdc++.h>

using namespace std;
int hobby[1010]{};
int *father;

void init(int *father, int n) {
    for (int i = 1; i <= n; ++i)
        father[i] = i;
}

int findFather(int p) {
    if (p == father[p])
        return p;
    return findFather(father[p]);
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, k, tmp;
    cin >> n;
    father = new int[n + 1];
    init(father, n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j) {
            cin >> tmp;
            if (hobby[tmp] == 0)
                hobby[tmp] = i;
            else {
                int f1 = findFather(hobby[tmp]);
                int f2 = findFather(i);
                if (f1 != f2)
                    father[f1] = f2;
            }
        }
    }

    int *m = new int[n + 1]{};
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int f = findFather(i);
        if (m[f] == 0)
            ans++;
        m[f]++;
    }
    sort(m, m + n + 1, cmp);
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << m[i];
        if (i < ans - 1)
            cout << " ";
    }
    delete[]m;
    delete[]father;

}
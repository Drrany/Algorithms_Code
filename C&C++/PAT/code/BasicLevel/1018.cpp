#include <bits/stdc++.h>

using namespace std;

struct situation {
    int win = 0;
    int winMap[3] = {0, 0, 0};
    int draw = 0;
    int lose = 0;
};

map<char, int> gesture = {{'C', 0},
                          {'J', 1},
                          {'B', 2}};
char getChar[] = {'C', 'J', 'B'};

int main() {
    int count;
    cin >> count;
    situation A, B;
    for (int i = 0; i < count; ++i) {
        char a, b;
        cin >> a >> b;
        if (a == b) {
            A.draw++;
            B.draw++;
        } else {
            int na = gesture[a];
            int nb = gesture[b];
            if (na - nb == -1 || na - nb == 2) {
                A.win++;
                A.winMap[na]++;
                B.lose++;
            } else {
                B.win++;
                B.winMap[nb]++;
                A.lose++;
            }
        }
    }

    cout << A.win << " " << A.draw << " " << A.lose << endl
         << B.win << " " << B.draw << " " << B.lose << endl;

    int ia = 0, ib = 0;
    for (int i = 1; i < 3; ++i) {
        if (A.winMap[ia] <= A.winMap[i] && getChar[i] < getChar[ia])
            ia = i;
        if (B.winMap[ib] <= B.winMap[i] && getChar[i] < getChar[ib])
            ib = i;
    }
    cout << getChar[ia] << " " << getChar[ib];
}
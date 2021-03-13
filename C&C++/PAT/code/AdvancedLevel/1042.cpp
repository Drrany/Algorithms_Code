#include <bits/stdc++.h>

using namespace std;


void shuffling(int *arr, string *cards) {
    string *n = new string[55];
    for (int i = 1; i <= 54; ++i)
        n[arr[i]] = cards[i];
    for (int i = 1; i <= 54; ++i)
        cards[i] = n[i];
}

int main() {
    int times;
    cin >> times;
    int arr[55];
    string cards[55] = {" ",
                        "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                        "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                        "J1", "J2"
    };
    for (int i = 1; i < 55; ++i)
        cin >> arr[i];
    for (int i = 0; i < times; ++i)
        shuffling(arr, cards);
    for (int i = 1; i < 54; ++i)
        cout << cards[i] << " ";
    cout << cards[54];

}
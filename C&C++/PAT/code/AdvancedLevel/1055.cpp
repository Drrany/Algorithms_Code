#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    int age;
    int worth;
};

bool cmp(person a, person b) {
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else return a.name < b.name;
}

int main() {
    int n, m;
    cin >> n >> m;
    person *arr = new person[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].name >> arr[i].age >> arr[i].worth;
    sort(arr, arr + n, cmp);
    int num, minAge, maxAge;
    for (int i = 0; i < m; ++i) {
        cin >> num >> minAge >> maxAge;
        cout << "Case #" << i + 1 << ":" << endl;
        int count = 0;
        for (int j = 0; j < n && count < num; ++j) {
            if (arr[j].age >= minAge && arr[j].age <= maxAge) {
                count++;
                cout << arr[j].name << " " << arr[j].age << " " << arr[j].worth << endl;
            }
        }
        if (count == 0)
            cout << "None" << endl;
    }

}
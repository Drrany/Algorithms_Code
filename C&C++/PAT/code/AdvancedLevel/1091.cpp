#include <bits/stdc++.h>

using namespace std;

int xOffset[] = {1, -1, 0, 0, 0, 0};
int yOffset[] = {0, 0, 1, -1, 0, 0};
int zOffset[] = {0, 0, 0, 0, 1, -1};
int arr[62][1288][130]{};

int main() {

    int m, n, l, t, ans = 0;
    cin >> m >> n >> l >> t;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n; ++k) {
                cin >> arr[i][j][k];
            }
        }
    }
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (arr[i][j][k] == 1) {
                    int count = 0;
                    queue<int *> q;
                    int *tmp1 = new int[3];
                    tmp1[0] = i;
                    tmp1[1] = j;
                    tmp1[2] = k;
                    q.push(tmp1);
                    count++;
                    while (!q.empty()) {
                        int *tmp = q.front();
                        arr[tmp[0]][tmp[1]][tmp[2]] = 0;
                        q.pop();
                        for (int i1 = 0; i1 < 6; ++i1) {
                            int z = tmp[0] + zOffset[i1];
                            int y = tmp[1] + yOffset[i1];
                            int x = tmp[2] + xOffset[i1];
                            if (arr[z][y][x] == 1) {
                                int *tmp2 = new int[3];
                                tmp2[0] = z;
                                tmp2[1] = y;
                                tmp2[2] = x;
                                q.push(tmp2);
                                count++;
                                arr[z][y][x] = 0;
                            }
                        }
                    }
                    if (count >= t)
                        ans += count;
                }
            }
        }
    }

    cout << ans;


}
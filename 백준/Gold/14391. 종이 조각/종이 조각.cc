#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[5][5];
int ans = INT_MIN;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;++i) {
        string str;
        cin >> str;

        for (int j=0;j<m;++j) {
            arr[i][j] = str[j] - '0';
        }
    }

    for (int mask=0;mask < (1 << (m*n));++mask) {
        int sum = 0;

        // 가로 합
        for (int i=0;i<n;++i) {
            int cur = 0;

            for (int j=0;j<m;++j) {
                int idx = i * m + j;

                if ((mask & (1 << idx)) == 0) {
                    cur = cur * 10 + arr[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        // 세로 합
        for (int j=0;j<m;++j) {
            int cur = 0;

            for (int i=0;i<n;++i) {
                int idx = i * m + j;

                if ((mask & (1 << idx)) != 0) {
                    cur = cur * 10 + arr[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ans = max(ans, sum);
    }

    cout << ans;
}
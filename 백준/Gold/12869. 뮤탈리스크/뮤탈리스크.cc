#include <bits/stdc++.h>

using namespace std;

int n;
int scv[4];
int dmg[6][3] = {
    {9,3,1},{9,1,3},
    {3,9,1},{3,1,9},
    {1,9,3},{1,3,9}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> scv[i];
    }

    // dp[i][j][k]: 각각 1번, 2번, 3번 SCV가 체력 i,j,k일 때 최소 공격 횟수
    int dp[61][61][61];
    for (int i=0;i<=60;++i) {
        for (int j=0;j<=60;++j) {
            for (int k=0;k<=60;++k) {
                dp[i][j][k] = 1e9;
            }
        }
    }

    dp[scv[1]][scv[2]][scv[3]] = 0;

    for (int i=scv[1];i>=0;--i) {
        for (int j=scv[2];j>=0;--j) {
            for (int k=scv[3];k>=0;--k) {
                for (auto atk : dmg) {
                    int ni = max(0, i - atk[0]);
                    int nj = max(0, j - atk[1]);
                    int nk = max(0, k - atk[2]);
                    dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + 1);
                }
            }
        }
    }

    cout << dp[0][0][0];
}
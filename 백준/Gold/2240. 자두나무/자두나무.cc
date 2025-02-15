#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, w;
	cin >> t >> w;

	int pos[1001];

	for (int i = 1; i <= t; i++) cin >> pos[i];

	// 시간, 움직인 횟수, 나무 위치
	int dp[1001][31][3];
	
	// 처음엔 1번에 위치
	dp[1][0][1] = (pos[1] == 1);
	// 2번에 위치하면 1칸 움직인거
	dp[1][1][2] = (pos[1] == 2);

	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			// 가만히 있을땐 단순히 더해주면됨
			if (j == 0) {
				dp[i][j][1] = dp[i - 1][j][1] + (pos[i] == 1);
				dp[i][j][2] = dp[i - 1][j][2] + (pos[i] == 2);
			}
			else {
				// 나무1 -> 나무1 or 나무2 -> 나무1
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + (pos[i] == 1);
				// 나무2 -> 나무2 or 나무1 -> 나무2
				dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + (pos[i] == 2);
			}
		}
	}

	int M = 0;

	for (int i = 0; i <= w; i++) {
		M = max(M, max(dp[t][i][1], dp[t][i][2]));
	}

	cout << M;
}
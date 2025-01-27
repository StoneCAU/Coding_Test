#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	int game[101][101];
	long long dp[101][101] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> game[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int go = game[i][j];
			int x = i + go;
			int y = j + go;

			if (!dp[i][j]) continue;
			if (i == n - 1 && j == n - 1) continue;
			if (x >= 0 && x < n) dp[x][j] = dp[x][j] + dp[i][j];
			if (y >= 0 && y < n) dp[i][y] = dp[i][y] + dp[i][j];
 		}
	}

	cout << dp[n - 1][n - 1];
}
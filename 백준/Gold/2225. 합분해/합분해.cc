#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int dp[201][201] = { 0, };

	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= k; j++) {
			if (i == 1) {
				dp[i][j] = j;
				continue;
			}

			if (j == 1) {
				dp[i][j] = 1;
				continue;
			}

			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[n][k] % 1000000000;
}
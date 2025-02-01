#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	int dp[12];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}

		cout << dp[n] << "\n";
	}

}
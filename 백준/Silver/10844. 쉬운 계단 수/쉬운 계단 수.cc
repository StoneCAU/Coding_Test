#include <bits/stdc++.h>

using namespace std;

int main() {
	long long dp[101][10];

	int n;

	cin >> n;

	dp[1][0] = 0;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0;
			if (j != 0) dp[i][j] += dp[i - 1][j - 1] % 1000000000;
			if (j != 9) dp[i][j] += dp[i - 1][j + 1] % 1000000000;
		}
	}

	long long sum = 0;

	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i] % 1000000000;
	}

	cout << sum % 1000000000;

}
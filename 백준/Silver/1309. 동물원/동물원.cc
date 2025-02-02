#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long dp[100001][3] = { 0, };

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2] % 9901;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2] % 9901;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] % 9901;
	}

	long long sum = 0;

	for (int i = 0; i <= 2; i++) {
		sum += dp[n][i] % 9901;
	}

	cout << sum % 9901; 
}
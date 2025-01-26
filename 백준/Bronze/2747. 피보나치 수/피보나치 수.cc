#include <bits/stdc++.h>

using namespace std;

int main() {

	int dp[46];

	dp[1] = 1;
	dp[2] = 1;

	int n;

	cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];
}
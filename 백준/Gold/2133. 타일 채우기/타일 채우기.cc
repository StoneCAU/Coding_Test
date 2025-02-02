#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[31] = { 0, };
	
	dp[1] = 0;
	dp[2] = 3;
	dp[4] = 11;

	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}


	for (int i = 6; i <= n; i += 2) {

		dp[i] = dp[i-2] * dp[2] + 2;

		for (int j = i-4; j >= 2; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}

	cout << dp[n];

}
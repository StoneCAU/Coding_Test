#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(100001, 100001);

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int num = (int)sqrt(i);

		dp[num * num] = 1;

		for (int j = num; j >= 1; j--) {
		
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}

	}

	cout << dp[n];
}
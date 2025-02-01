#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int coin[101];
	vector<int> dp(100001, 0);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];

}
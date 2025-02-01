#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[101];
	vector<int> dp(100001, 100001);

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {

			dp[j] = min(dp[j], dp[j - arr[i]] +1);
		}
	}

	if (dp[k] == 100001) cout << -1;
	else cout << dp[k];
}
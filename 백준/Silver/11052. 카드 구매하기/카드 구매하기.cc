#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[1001] = { 0, };
	int card[1001];

	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = max(dp[j], dp[j-i] + card[i]);
		}
	}

	cout << dp[n];
}
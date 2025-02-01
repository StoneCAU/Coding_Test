#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[100001];
	int arr[100001];
	int M;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	M = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		M = max(M, dp[i]);
	}

	cout << M;

}
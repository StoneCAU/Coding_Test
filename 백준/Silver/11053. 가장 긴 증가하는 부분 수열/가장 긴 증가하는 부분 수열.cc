#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;

	int dp[1001];
	int arr[1001];
	int M = 1;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		
		M = max(M, dp[i]);
	}
	

	cout << M;
}
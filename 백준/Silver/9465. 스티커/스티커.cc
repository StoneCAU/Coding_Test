#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		int s[2][100001];
		int dp[2][100001] = { 0, };

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> s[0][j];
		}

		for (int j = 0; j < n; j++)
		{
			cin >> s[1][j];
		}

		dp[0][0] = s[0][0];
		dp[1][0] = s[1][0];
		dp[0][1] = s[0][1] + dp[1][0];
		dp[1][1] = s[1][1] + dp[0][0];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = s[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = s[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		
		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";

	}

}
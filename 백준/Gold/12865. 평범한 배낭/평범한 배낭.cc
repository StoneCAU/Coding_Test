#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	vector<pair<int,int>> item;

	item.push_back({ 0,0 });

	int dp[101][100001] = { 0, };

	for (int i = 0; i < n; i++)
	{
		int W, V;

		cin >> W >> V;

		item.push_back({ W, V });
	}

	for (int i = 1; i <= n; i++)
	{
		int curW = item[i].first;
		int curV = item[i].second;

		for (int j = 1; j <= k; j++)
		{
			if (j < curW) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curW] + curV);
		}
	}

	cout << dp[n][k];

}


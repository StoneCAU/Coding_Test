#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	int dp[1001][1001] = { 0, };

	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}

	cout << dp[s1.size()][s2.size()];

}


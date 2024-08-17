#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int dp[1002];
	int res = 1;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;

		cin >> num;

		v.push_back(num);
	}

	dp[0] = 1;

	for (int i = 1; i < n; i++) 
	{
		int M = 0;

		for (int j = 0; j <= i; j++) 
		{
			if (v[i] > v[j])
			{
				if (M < dp[j]) M = dp[j];
			}
		}

		if (!M) dp[i] = 1;
		else dp[i] = M + 1;

		if (res < dp[i]) res = dp[i];
	}

	cout << res;

}
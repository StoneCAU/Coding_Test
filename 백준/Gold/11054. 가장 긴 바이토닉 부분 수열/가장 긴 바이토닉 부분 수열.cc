#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int dp1[1001];
	int dp2[1001];
	int res = 0;

	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}

	dp1[0] = 1;

	for (int i = 1; i < n; i++)
	{
		int M = 0;

		for (int j = 0; j <= i; j++)
		{
			if (v[i] > v[j])
			{
				if (M < dp1[j]) M = dp1[j];
			}
		}

		if (!M) dp1[i] = 1;
		else dp1[i] = M + 1;
	}

	reverse(v.begin(), v.end());

	dp2[0] = 1;

	for (int i = 1; i < n; i++)
	{
		int M = 0;

		for (int j = 0; j <= i; j++)
		{
			if (v[i] > v[j])
			{
				if (M < dp2[j]) M = dp2[j];
			}
		}

		if (!M) dp2[i] = 1;
		else dp2[i] = M + 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (dp1[i] + dp2[n - i - 1] > res) res = dp1[i] + dp2[n - i - 1] - 1;
	}

	cout << res;

}



#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
long long dp[91];
long long one = 0;
long long zero = 1;

void pn()
{
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] * 2 - one;
		one = zero;
		zero = dp[i] - one;
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	pn();

	cout << dp[n];
}
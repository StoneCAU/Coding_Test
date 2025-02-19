#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	unordered_map<int, pair<int, int>> m;

	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;

		pair<int, int> pair;
		pair.first = t;
		pair.second = p;

		m[i] = pair;
	}

	int dp[16] = { 0, };

	for (int i = 1; i <= n; i++) {
		int t = m[i].first;
		int p = m[i].second;

		if (i + t - 1 > n) continue;

		dp[i] = max(dp[i], p);


		int chI = i + t;

		while (chI <= n) {
			int chT = m[chI].first;
			int chP = m[chI].second;

			if (chI + chT - 1 > n) {
				chI++;
				continue;
			}

			dp[chI] = max(dp[chI], dp[i] + chP);
			chI++;
		}

	}

	cout << *max_element(dp, dp + 16);;
}
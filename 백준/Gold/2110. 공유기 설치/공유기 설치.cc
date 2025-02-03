#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<long long> x;

bool possible(int dist) {
	int cnt = 1;
	int prev = x[0];

	for (int i = 1; i <= n; i++) {
		if (x[i] - prev >= dist) {
			cnt++;
			prev = x[i];
		}
	}

	if (cnt >= c) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		x.push_back(num);
	}

	sort(x.begin(), x.end());

	long long low = 1;
	long long high = x[n - 1] - x[0];
	long long res = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		if (possible(mid)) {
			res = max(res, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << res;
}
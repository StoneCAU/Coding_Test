#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<long long> v;
	bool onlyZero = true;

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;

		if (num != 0) onlyZero = false;

		v.push_back(num);
	}

	if (onlyZero) {
		cout << 0;
		return 0;
	}

	sort(v.begin(), v.end());

	long long low = 0;
	long long high = v[n - 1];
	long long max = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long div = 0;

		if (mid == 0) mid++;

		for (int i = 0; i < n; i++) {
			long long q = v[i] / mid;

			if (q > 0) {
				div += q;
			}
		}

		if (div >= k) {
			max = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << max;
}
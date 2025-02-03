#include <bits/stdc++.h>

using namespace std;

long long binarySearch(vector<long long>& b, long long target) {
	long long low = 0;
	long long high = b.size() - 1;
	long long m = 1000000001;
	long long num = 1000000001;

	while (low <= high) {
		long long mid = (low + high) / 2;

		if (b[mid] == target) return target;
		else if (b[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

		if (m >= abs(b[mid] - target)) {
			if (m == abs(b[mid] - target)) {
				if (num > b[mid]) num = b[mid];
				continue;
			}

			m = abs(b[mid] - target);
			num = b[mid];
		}
	}

	return num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long t;
	cin >> t;

	while (t--) {
		long long n, m;
		cin >> n >> m;

		vector<long long> a;
		vector<long long> b;

		for (long long i = 0; i < n; i++) {
			long long num;
			cin >> num;
			a.push_back(num);
		}

		for (long long i = 0; i < m; i++) {
			long long num;
			cin >> num;
			b.push_back(num);
		}

		sort(b.begin(), b.end());

		long long sum = 0;

		for (long long i = 0; i < n; i++) {
			sum += binarySearch(b, a[i]);
		}

		cout << sum << "\n";
	}
}
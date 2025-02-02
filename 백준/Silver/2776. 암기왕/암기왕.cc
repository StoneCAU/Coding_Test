#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& real, int target) {
	int low = 0;
	int high = real.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (real[mid] == target) return 1;
		else if (real[mid] > target) {
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return 0;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> real;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			real.push_back(num);
		}

		sort(real.begin(), real.end());

		int m;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;

			cout << binarySearch(real, num) << "\n";
		}
	}

}
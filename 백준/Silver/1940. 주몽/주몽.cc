#include <bits/stdc++.h>

using namespace std;

bool count(vector<int> &v, int target) {
	int low = 0;
	int high = v.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (v[mid] == target) return true;

		if (v[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int res = 0;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		if (count(v, m - v[i])) res++;
	}

	cout << res / 2;
}
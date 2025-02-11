#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int j;
	cin >> j;

	int count = 0;
	int start = 1;
	int end = m;

	for (int i = 0; i < j; i++) {
		int p;
		cin >> p;

		if (p >= start && p <= end) continue;
		else if (p > end) {
			while (1) {
				if (p >= start && p <= end) break;
				start++;
				end++;
				count++;
			}
		}
		else if (p < start) {
			while (1) {
				if (p >= start && p <= end) break;
				start--;
				end--;
				count++;
			}
		}
	}

	cout << count;

}
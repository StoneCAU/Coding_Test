#include <bits/stdc++.h>

using namespace std;

int arr[1025][1025];

int cal(int i, int j) {
	int dx = i * 2;
	int dy = j * 2;

	vector<int> v;

	for (int a = dx - 1; a <= dx; a++) {
		for (int b = dy - 1; b <= dy; b++) {
			v.push_back(arr[a][b]);
		}
	}

	sort(v.begin(), v.end(), greater<int>());

	return v[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	while (n != 1) {
		n /= 2;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = cal(i, j);
			}
		}
	}

	cout << arr[1][1];
}
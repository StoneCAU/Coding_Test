#include <bits/stdc++.h>

using namespace std;

int n;
int arr[65][65] = { 0, };

void func(int x, int y, int n) {
	if (n == 1) {
		cout << arr[x][y];
		return;
	}

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != arr[x][y]) {
				cout << "(";

				func(x, y, n / 2);
				func(x, y + n / 2, n / 2);
				func(x + n / 2, y, n / 2);
				func(x + n / 2, y + n / 2, n / 2);

				cout << ")";
				return;
			}
		}
	}

	cout << arr[x][y];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	func(0, 0, n);

}
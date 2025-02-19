#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;

	int count = 1;

	while (x != 1) {
		if (x % 2 == 1) count++;
		x /= 2;
	}

	cout << count;
}
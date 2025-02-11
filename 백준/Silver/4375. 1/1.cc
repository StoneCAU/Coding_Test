#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	while (cin >> n) {

		int num = 1;
		int k = 1;

		while (1) {
			if (num % n == 0) break;
			num = (num * 10) %n + 1 %n;
			num %= n;
			k++;
		}
		
		cout << k << "\n";
	}

}
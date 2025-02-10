#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int c;
		cin >> c;

		unordered_map<string, int> m;
		set<string> s;

		for (int i = 0; i < c; i++) {
			string a, b;
			cin >> a >> b;

			if (!m[b]) m[b] = 1;
			else m[b]++;

			s.insert(b);
		}

		int sum = 1;

		for (auto it : s) {
			sum *= (m[it] +1);
		}

		cout << sum - 1 << "\n";
	}
}
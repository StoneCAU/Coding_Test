#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	unordered_map<int, int> m;

	for (int i = 0; i < 3; i++) {
		int s, e;
		cin >> s >> e;
	
		for (int i = s; i < e; i++) {
			if (!m[i]) m[i] = 1;
			else m[i]++;
		}
	}

	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		if (!m[i]) continue;

		if (m[i] == 1) sum += a;
		else if (m[i] == 2) sum += 2 * b;
		else if (m[i] == 3) sum += 3 * c;
	}
	
	cout << sum;
}
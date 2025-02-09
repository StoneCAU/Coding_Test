#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<char, int> m;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (!m[s[0]]) m[s[0]] = 1;
		else m[s[0]]++;
	}

	bool chk = false;

	for (char c = 'a'; c <= 'z'; c++) {
		if (m[c] >= 5) {
			if (!chk) chk = true;
			cout << c;
		}
	}

	if (!chk) cout << "PREDAJA";
}
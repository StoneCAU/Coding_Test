#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	string s;
	cin >> s;

	unordered_map<char, int> m;

	for (int i = 0; i < s.length(); i++) {
		if (!m[s[i]]) m[s[i]] = 1;
		else m[s[i]] += 1;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		cout << m[c] << " ";
	}
}
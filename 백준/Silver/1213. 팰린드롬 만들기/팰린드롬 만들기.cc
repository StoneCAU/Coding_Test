#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	unordered_map<char, int> m;
	set<char> set;

	for (int i = 0; i < s.length(); i++) {
		if (!m[s[i]]) m[s[i]] = 1;
		else m[s[i]]++;
		set.insert(s[i]);
	}

	if (s.length() % 2 == 0) {
		string res = "";

		for (auto it : set) {
			if (m[it] % 2 != 0) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}

			for (int i = 0; i < m[it] / 2; i++) {
				res += it;
			}
		}
		sort(res.begin(), res.end());

		string rev = res;
		reverse(rev.begin(), rev.end());

		res += rev;
		cout << res;
	}
	else {
		int odd = 0;
		char center;
		string res = "";

		for (auto it : set) {
			if (m[it] % 2 != 0) {
				odd++;
				center = it;

				if (odd > 1) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}

				if (m[it] >= 3) {
					for (int i = 0; i < m[it] / 2; i++) {
						res += it;
					}
				}
			}
			else {
				for (int i = 0; i < m[it] / 2; i++) {
					res += it;
				}
			}
		}

		sort(res.begin(), res.end());

		string rev = res;
		reverse(rev.begin(), rev.end());

		res += center;
		res += rev;

		cout << res;
	}
	
}
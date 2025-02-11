#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char arr[] = { 'a','e','i','o','u' };

	while (1) {
		string s;
		cin >> s;

		if (s == "end") break;

		unordered_map<char, int> m;

		int ja = 0;
		int mo = 0;
		bool chk = false;

		for (int i = 0; i < s.length(); i++) {
			char cur = s[i];

			if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u') {
				if (!m[cur]) m[cur] = 1;
				else m[cur]++;
				mo++;
				ja = 0;
			}
			else {
				ja++;
				mo = 0;
			}

			// 모음 또는 자음 3회 연속 예외
			if (ja >= 3 || mo >= 3) {
				cout << "<" + s + "> is not acceptable.\n";
				chk = true;
				break;
			}

			// 같은 글자 연속 2번 예외
			if (i == 0) continue;
			char prev = s[i - 1];

			if (cur != 'e' && cur != 'o') {
				if (cur == prev) {
					cout << "<" + s + "> is not acceptable.\n";
					chk = true;
					break;
				}
			}
		}

		if (chk) continue;

		// 모음 1회 이상
		bool has = false;

		for (int i = 0; i < 5; i++) {
			if (m[arr[i]]) {
				has = true;
				break;
			}
		}

		if (has) cout << "<" + s + "> is acceptable.\n";
		else cout << "<" + s + "> is not acceptable.\n";
	
	}
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	string p;
	cin >> p;

	int star = p.find("*");
	int minLen = p.length() - 1;

	while(n--) {
		string s;
		cin >> s;

		if (s.length() < minLen) {
			cout << "NE\n";
			continue;
		}

		bool chk = false;

		// 처음 ~ (별 - 1)
		for (int i = 0; i < star; i++) {
			if (s[i] != p[i]) {
				cout << "NE\n";
				chk = true;
				break;
			}
		}

		if (chk) continue;

		int checkCount = p.length() - star;

		for (int i = 0; i < checkCount ; i++) {
			if (p[p.length() - i] != s[s.length() - i]) {
				cout << "NE\n";
				chk = true;
				break;
			}
		}

		if (chk) continue;
		else cout << "DA\n";
	}

}
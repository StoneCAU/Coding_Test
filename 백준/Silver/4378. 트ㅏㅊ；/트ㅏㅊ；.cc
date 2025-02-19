#include <bits/stdc++.h>

using namespace std;

string str = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				cout << " ";
				continue;
			}

			if (s[i] == 'Q' || s[i] == 'A' || s[i] == 'Z' || s[i] == '`' || s[i] == '	') {
				cout << s[i];
				continue;
			}

			int idx = str.find(s[i]);
			cout << str[idx - 1];
		}
		cout << "\n";
	}
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		int df;
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] + 13 > 'z') {
				df = 13 - ('z'- s[i]) - 1;
				s[i] = 'a' + df;
			}
			else s[i] += 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] + 13 > 'Z') {
				df = 13 - ('Z' - s[i]) - 1;
				s[i] = 'A' + df;
			}
			else s[i] += 13;
		}

	}

	cout << s;
}
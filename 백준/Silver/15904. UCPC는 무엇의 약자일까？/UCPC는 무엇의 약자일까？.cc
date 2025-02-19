#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	getline(cin, s);

	string temp = "";

	for (int i = 0; i < s.size(); i++) {
		if (temp == "") {
			if (s[i] == 'U') temp += s[i];
		}
		else if (temp == "U") {
			if (s[i] == 'C') temp += s[i];
		}
		else if (temp == "UC") {
			if (s[i] == 'P') temp += s[i];
		}
		else if (temp == "UCP") {
			if (s[i] == 'C') {
				temp += s[i];
				break;
			}
		}
	}

	if (temp == "UCPC") cout << "I love UCPC";
	else cout << "I hate UCPC";
}
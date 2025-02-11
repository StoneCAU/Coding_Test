#include <bits/stdc++.h>

using namespace std;

bool count(string s) {
	stack<char> stk;

	for (int i = 0; i < s.length(); i++) {
		char cur = s[i];

		if (stk.empty()) {
			stk.push(cur);
		}
		else {
			if (stk.top() == cur) {
				stk.pop();
			}
			else {
				stk.push(cur);
			}
		}
	}

	if (stk.empty()) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int res = 0;
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (count(s)) res++;
	}

	cout << res;
}
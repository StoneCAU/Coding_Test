#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		stack<char> stk;

		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			char cur = s[i];
			
			if (stk.empty()) {
				stk.push(cur);
				continue;
			}

			if (!stk.empty() && stk.top() == '(') {
				if (cur == ')') stk.pop();
				else stk.push(cur);
			}
			else {
				stk.push(cur);
			}
		}

		if (stk.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	while (1) {
		getline(cin, s);

		if (s == ".") break;

		stack<char> stk;

		for (int i = 0; i < s.length(); i++) {
			char cur = s[i];

			if (cur != '(' && cur != ')' && cur != '[' && cur != ']') continue;

			if (stk.empty()) {
				stk.push(cur);
				continue;
			}

			if (!stk.empty()) {
				char top = stk.top();

				if (top == '(' && cur == ')') stk.pop();
				else if (top == '[' && cur == ']') stk.pop();
				else stk.push(cur);
			}
			else stk.push(cur);
		}

		if (stk.empty()) cout << "yes\n";
		else cout << "no\n";
	}
}
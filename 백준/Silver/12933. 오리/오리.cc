#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> visited(2501);
unordered_map<char, int> m;

bool done(int n) {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt = 0;
	bool chk = false;

	for(int j=0;j<s.length();j++) {
		if (chk) {
			cnt++;
			chk = false;
		}

		if (visited[j]) continue;
		
		string temp = "";

		for (int i = j; i < s.length(); i++) {
			if (visited[i]) continue;

			bool flag = false;

			if (s[i] == 'q' && temp == "") {
				temp += s[i];
				visited[i] = 1;
				m[s[i]]++;
			}
			else if (s[i] == 'u' && temp == "q") {
				temp += s[i];
				visited[i] = 1;
				m[s[i]]++;
			}
			else if (s[i] == 'a' && temp == "qu") {
				temp += s[i];
				visited[i] = 1;
				m[s[i]]++;
			}
			else if (s[i] == 'c' && temp == "qua") {
				temp += s[i];
				visited[i] = 1;
				m[s[i]]++;
			}
			else if (s[i] == 'k' && temp == "quac") {
				temp += s[i];
				visited[i] = 1;
				m[s[i]]++;
			}

			if (temp == "quack") {
				temp = "";
				chk = true;
			}
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (!visited[i]) {
			cout << -1;
			return 0;
		}
	}

	int num = m['q'];

	if (m['u'] != num || m['a'] != num || m['c'] != num || m['k'] != num) cout << -1;
	else cout << cnt;
}
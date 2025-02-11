#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				return a[i] < b[i];
			}
		}
	}
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			string numStr = "";
			char cur = s[j];

			if (cur >= '0' && cur <= '9') {
				int k = j;

				while (1) {
					char temp  = s[k];

					if (temp >= '0' && temp <= '9') {
						if (numStr == "0") {
							numStr = temp;
							k++;
							continue;
						}
						numStr += temp;
						k++;
						continue;
					}

					j = k - 1;

					v.push_back(numStr);
					break;
				}
			}			
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << "\n";
	}
}
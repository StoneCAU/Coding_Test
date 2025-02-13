#include <bits/stdc++.h>

using namespace std;

int sum = 0;
int x;
int root;

vector<vector<int>> v(51);

void dfs(int s) {
	if (s == x) return;

	if (v[s].size() == 0) {
		sum++;
		return;
	}

	for (int i = 0; i < v[s].size(); i++) {
		dfs(v[s][i]);

		if (v[s][i] == x && v[s].size() == 1) sum++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == -1) {
			root = i;
			continue;
		}

		v[a].push_back(i);
	}

	cin >> x;

	dfs(root);

	cout << sum;
}
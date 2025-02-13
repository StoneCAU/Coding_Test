#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> v(10001);
int M = 0;
int sum = 0;
vector<int> visited(10001);

void dfs(int s) {
	if (visited[s]) return;

	sum++;
	visited[s] = 1;
	
	if (v[s].size() == 0) {
		return;
	}

	for (int i = 0; i < v[s].size(); i++) {
		dfs(v[s][i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[b].push_back(a);
	}

	vector<int> res;

	for (int i = 1; i <= n; i++) {
		sum = 0;
		fill(visited.begin(), visited.end(), 0);
	
		dfs(i);

		if (sum > M) {
			res.clear();
			M = sum;
			res.push_back(i);
		}
		else if (sum == M) {
			res.push_back(i);
		}

	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}
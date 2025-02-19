#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100001];
int visited[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(&visited[0], &visited[0] + 100001, -1);

	queue<int> q;
	q.push(n);
	visited[n] = n;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
	
		if (x == k) break;

		int next[] = { x - 1, x + 1, x * 2 };

		for (int i = 0; i < 3; i++) {
			if (next[i] < 0 || next[i] > 100000) continue;
			if (visited[next[i]] != -1) continue;
			visited[next[i]] = x;
			q.push(next[i]);
		}
	}

	vector<int> path;
	int cur = k;
	while (cur != n) {
		path.push_back(cur);
		cur = visited[cur];
	}
	path.push_back(n);

	cout << path.size() - 1 << "\n";

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
}
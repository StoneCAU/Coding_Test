#include <bits/stdc++.h>

using namespace std;

int visited[10000000];

queue<int> q;

int bfs(int n) {
	q.push(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int xx;

			if (i == 0) {
				if (x % 3 == 0) {
					xx = x / 3;
				}
				else continue;
			}
			else if (i == 1) {
				if (x % 2 == 0) {
					xx = x / 2;
				}
				else continue;
			}
			else xx = x - 1;

			if (xx < 0) continue;
			if (visited[xx]) continue;

			visited[xx] = visited[x] + 1;

			if (xx == 1) return visited[xx];

			q.push(xx);
		}
	}

	return visited[1];
}

int main() {
	int n;

	cin >> n;

	cout << bfs(n);
}
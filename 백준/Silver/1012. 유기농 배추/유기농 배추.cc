#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int arr[52][52];
int visited[52][52];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void bfs(int a, int b) {
	q.push({ a, b });
	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (visited[xx][yy]) continue;
			if (!arr[xx][yy]) continue;
			visited[xx][yy] = 1;
			q.push({ xx, yy });
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int count = 0;
		fill(&visited[0][0], &visited[51][51], 0);
		fill(&arr[0][0], &arr[51][51], 0);

		while (!q.empty()) {
			q.pop();
		}

		cin >> m >> n >> k;
		
		vector<pair<int, int>> v;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
		
			v.push_back({ x, y });
			arr[x][y] = 1;
		}

		for (int i = 0; i < k; i++) {
			int x = v[i].first;
			int y = v[i].second;

			if (visited[x][y]) continue;
			bfs(x, y);
			count++;
		}

		cout << count << "\n";
	}

}
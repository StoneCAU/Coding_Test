#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;

int bfs() {
	q.push({ 0,0 });
	visited[0][0] = 1;

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
			visited[xx][yy] = visited[x][y] + 1;
			q.push({ xx, yy });
			//cout << xx << " " << yy << "\n";
		}
	}

	return visited[n - 1][m - 1];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	cout << bfs();

}
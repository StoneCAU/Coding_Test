#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[501][501];
int visited[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (visited[x][y] != -1) return visited[x][y];

	visited[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
		if (arr[x][y] <= arr[xx][yy]) continue;
		visited[x][y] = visited[x][y] + dfs(xx, yy);
	}
	
	return visited[x][y];
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
}
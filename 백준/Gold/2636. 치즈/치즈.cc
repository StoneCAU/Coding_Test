#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

vector<vector<int>> arr(101, vector<int>(101, 0));

bool isBlank(vector<vector<int>>& v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) return false;
		}
	}
	return true;
}

int getCount(vector<vector<int>>& v) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) count++;
		}
	}

	return count;
}

vector<pair<int, int>> getMelt(vector<vector<int>>& v) {
	vector<pair<int, int>> melt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == -1) melt.push_back({ i,j });
		}
	}

	return melt;
}

vector<vector<int>> bfs(vector<vector<int>>& v, int a, int b) {
	int visited[101][101] = { 0, };
	visited[a][b] = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = xx + dx[i];
			int y = yy + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (v[x][y] == -1 || v[x][y] == 1) continue;
			if (visited[x][y]) continue;
			visited[x][y] = 1;
			q.push({ x, y });
			
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (v[nx][ny] == 1) v[nx][ny] = -1;
			}
		}
	}

	return v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> temp(arr.begin(), arr.end());

	int hour = 0;
	int prev = getCount(temp);

	while (1) {
		if (isBlank(temp)) break;

		hour++;
		
		temp = bfs(temp, 0, 0);

		vector<pair<int, int>> melt = getMelt(temp);

		for (int i = 0; i < melt.size(); i++) {
			int x = melt[i].first;
			int y = melt[i].second;

			temp[x][y] = 0;
		}

		prev = melt.size();
	}

	cout << hour << "\n" << prev;
}
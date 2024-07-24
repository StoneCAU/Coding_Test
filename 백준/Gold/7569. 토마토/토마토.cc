#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int arr[101][101][101];
int visited[101][101][101];
int n, m, h;
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,1,-1,0,0 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	queue<tuple<int, int, int>> q;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) q.push({ i,j,k });
				if (arr[i][j][k] == 0) visited[i][j][k] = -1;
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int nz = get<2>(cur) + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (visited[nx][ny][nz] >= 0) continue;
			visited[nx][ny][nz] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nx, ny, nz });
		}

	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < h; k++)
			{
				if (visited[i][j][k] == -1) {
					cout << "-1";
					return 0;
				}
				ans = max(ans, visited[i][j][k]);
			}
		}
	}

	cout << ans;
}
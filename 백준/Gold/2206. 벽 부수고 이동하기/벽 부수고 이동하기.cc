#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, m;
int arr[1002][1002];
int dist[1002][1002][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<pair<int, int>,int>> q;
vector<pair<int, int>> v;
vector<int> d;

void bfs(int x, int y)
{
	q.push({ {x, y}, 0 });

	while (!q.empty())
	{
		auto cur = q.front();

		if (cur.first.first == n && cur.first.second == m)
		{
			if (cur.second == 0)
				cout << dist[n][m][0] + 1;
			else cout << dist[n][m][1] + 1;

			return;
		}

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (!dist[nx][ny][1] && !cur.second && arr[nx][ny])
			{				
				dist[nx][ny][1] = dist[cur.first.first][cur.first.second][0] + 1;

				q.push({ {nx, ny}, 1 });
			}
			else if (!dist[nx][ny][0] && !cur.second && !arr[nx][ny])
			{
				dist[nx][ny][0] = dist[cur.first.first][cur.first.second][0] + 1;

				q.push({ {nx, ny}, 0 });
			}
			else if (!dist[nx][ny][1] && cur.second && !arr[nx][ny])
			{
				dist[nx][ny][1] = dist[cur.first.first][cur.first.second][1] + 1;

				q.push({ {nx, ny}, 1 });
			}
		}
	}
	cout << "-1";
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = s[j-1] - '0';

		}
	}

	bfs(1, 1);

	
	
}
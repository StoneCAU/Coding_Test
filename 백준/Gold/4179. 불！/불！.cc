#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int R, C;
char arr[1001][1001];
int visited[1001][1001];
int visited2[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	fill(&visited[0][0], &visited[0][0] + 1001 * 1001, -1);

	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < C; j++)
		{
			arr[i][j] = s[j];

			if (s[j] == 'F') {
				q1.push({ i,j });
				visited[i][j] = 0;
			}
			if (s[j] == 'J') {
				q2.push({ i,j });
			}
		}

	}



	while (!q1.empty())
	{
		int xx = q1.front().first;
		int yy = q1.front().second;

		q1.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (visited[nx][ny] != -1) continue;
			if (arr[nx][ny] == '#') continue;
			visited[nx][ny] = visited[xx][yy] + 1;
			q1.push({ nx, ny });
		}
	}


	while (!q2.empty())
	{
		int xx = q2.front().first;
		int yy = q2.front().second;

		q2.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << visited2[xx][yy] + 1;
				return 0;
			}
			if (visited2[nx][ny]) continue;
			if (arr[nx][ny] == '#') continue;
			if (visited[nx][ny] != -1 && visited[nx][ny] <= visited2[xx][yy] + 1) continue;
			visited2[nx][ny] = visited2[xx][yy] + 1;
			q2.push({ nx, ny });

		}
	}

	cout << "IMPOSSIBLE";

	
}
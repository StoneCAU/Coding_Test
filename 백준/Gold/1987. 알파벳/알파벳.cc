#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int r, c;
int M = 1;
char board[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int alphabet[26];

void dfs(int x, int y, int cnt)
{

	alphabet[board[x][y] - 'A'] = 1;

	if (M < cnt) M = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (alphabet[board[nx][ny] - 'A']) continue;
		dfs(nx, ny, cnt + 1);
	}

	alphabet[board[x][y] - 'A'] = 0;

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	dfs(0,0,1);

	cout << M;

}



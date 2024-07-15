#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int L, R, C;
int sx, sy, sz;
int ex, ey, ez;
char area[31][31][31];
int visited[31][31][31];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};

queue<tuple<int, int, int>> q;

void bfs(int z, int x, int y) {

	q.push({ z, x, y });

	visited[z][x][y] = 0;

	while (!q.empty())
	{
		int xx = get<1>(q.front());
		int yy = get<2>(q.front());
		int zz = get<0>(q.front());

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			int nz = zz + dz[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
			if (nx == sx && ny == sy && nz == sz) continue;
			if (area[nz][nx][ny] == '#') continue;
			if (visited[nz][nx][ny] != -1) continue;
			visited[nz][nx][ny] = visited[zz][xx][yy] + 1;
			if (area[nz][nx][ny] == 'E') return;
			q.push({ nz, nx, ny });

		}
	}

}

int main() {

	while (1) {

		fill(&visited[0][0][0], &visited[0][0][0] + 31 * 31 * 31, -1);
		fill(&area[0][0][0], &area[0][0][0] + 31 * 31 * 31, ' ');

		while (!q.empty())
			q.pop();

		cin >> L >> R >> C;

		if (!L && !R && !C) break;

		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					
					cin >> area[i][j][k];

					if (area[i][j][k] == 'S') {
						sx = j;
						sy = k;
						sz = i;
					}

					if (area[i][j][k] == 'E') {
						ex = j;
						ey = k;
						ez = i;
					}
				}
			}
		}

		bfs(sz, sx, sy);

		if (visited[ez][ex][ey] == -1) cout << "Trapped!\n";
		else {
			cout << "Escaped in " << visited[ez][ex][ey] << " minute(s).\n";
		}

	}

	return 0;
	
}
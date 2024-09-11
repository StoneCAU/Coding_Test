#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
int t = 0;
int board[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<pair<int, int>> q;

void inside()
{
	q.push({ 0, 0 });

	visited[0][0] = 1;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny]) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

void melt(int x, int y)
{
	// 외부 공기와 접촉된 면의 수
	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 0) sum++;
	}

	// 접촉면이 2개 이상이면 녹일 수 있음
	if (sum >= 2) board[x][y] = 2;
}

bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] > 0) return false;
		}
	}

	return true;
}



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	while (1)
	{
		// 다 녹았다면 return
		if (check()) break;

		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

		// 내부 공기 탐색
		// -1: 내부 공기, 0: 외부 공기, 1: 치즈, 2: 다음 없어질 치즈
		inside();

		vector<pair<int, int>> chz;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 치즈 칸은 vector에 담음
				if (board[i][j]) chz.push_back({ i,j });

				// 내부 공기인 칸은 -1로 변경
				if (visited[i][j]) continue;
				if (board[i][j]) continue;
				board[i][j] = -1;
			}
		}

		// 녹일 수 있는 칸 체크
		for(int i=0;i<chz.size();i++)
		{
			melt(chz[i].first, chz[i].second);
		}

		// 녹이는 과정
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 치즈를 녹임
				if (board[i][j] == 2)
				{
					board[i][j] = 0;
				}

				// 내부 공기는 다시 외부공기로 취급
				if (board[i][j] == -1)
				{
					board[i][j] = 0;
				}
			}
		}

		t++;
	}

	cout << t;
}



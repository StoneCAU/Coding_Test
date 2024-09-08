#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 기본 정보
int n;
int Time = 0;
int board[21][21];
int visited[21][21];
int fishChk[21][21];

// 아기 상어
pair<int, int> baby;
int Size = 2;
int eat = 0;

// 물고기 (좌표, 거리)
vector<vector<pair<int, int>>> fish(7);

// 이동
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

// 거리 측정 용도
queue<tuple<int, int, int>> d;

int dist(int vx, int vy)
{
	while (!d.empty()) d.pop();

	int x = baby.first;
	int y = baby.second;

	visited[x][y] = 1;

	d.push({ x,y,0 });

	//cout << "아기상어: " << x << " " << y << "=====\n";
	//cout << vx << " " << vy << "\n";

	while (!d.empty())
	{
		int xx = get<0>(d.front());
		int yy = get<1>(d.front());
		int len = get<2>(d.front());

		//cout << "why?" << xx << " " << yy << "\n";

		d.pop();

		if (xx == vx && yy == vy) return len;

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] > Size) continue;
			//cout << board[nx][ny] << " " << Size << "\n";
			visited[nx][ny] = 1;
			d.push({ nx, ny, len + 1 });
			//cout << "크기: " << board[nx][ny] << "\n";
			//cout << "push " << nx << " " << ny << " " << len + 1 << "\n";
		}
	}

	return 0;
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];

			// 아기 상어 위치
			if (board[i][j] == 9) 
			{
				baby.first = i;
				baby.second = j;
			}
			// 물고기 위치
			else if (board[i][j] > 0)
			{
				// 자연스럽게 왼쪽 위부터 먹도록 입력됨
				fish[board[i][j]].push_back({ i,j });
				fishChk[i][j] = 1;
			}
		}
	}
	while (1)
	{
		int minX;
		int minY;
		int minDist = 999999999;
		bool change = false;

		// 현 상황에서 먹을 수 있는 최적의 물고기 추출
		for (int i = 1; i < Size; i++)
		{
			if (i > 6) break;

			for (int j = 0; j < fish[i].size(); j++)
			{

				int x = fish[i][j].first;
				int y = fish[i][j].second;

				if (!fishChk[x][y]) continue;
	
				int len = dist(x, y);
				//cout << x << " " << y << " / 거리: " << len << "\n";
				fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);

				// 등호가 빠짐으로써 먼저나온 것(왼쪽 위)가 우선순위가 됨
				if (len <= minDist && len > 0)
				{
					if (len == minDist)
					{
						if (x < minX || (x == minX && y < minY))
						{
							minDist = len;
							minX = x;
							minY = y;
							change = true;
						}
					}
					else
					{
						minDist = len;
						minX = x;
						minY = y;
						change = true;
					}
					
				}
			}
		}

		if (!change) break;

		

		// 먹고 위치이동
		//cout << "\n";
		//cout << "======먹은 물고기의 크기: " << board[minX][minY] << "========\n";
		fishChk[minX][minY] = 0;
		board[baby.first][baby.second] = 0;
		baby.first = minX;
		baby.second = minY;
		board[minX][minY] = 9;
		eat++;
		Time += minDist;
		if (Size == eat)
		{
			Size++;
			eat = 0;
		}
		//cout << "위치 (" << minX << ", " << minY << ")\n";
		//cout << "시간: " << Time << "\n";
		//cout << "크기: " << Size << "\n";
		//cout << "먹은 수: " << eat << "\n";
		
	}
	
	cout << Time;
	
}



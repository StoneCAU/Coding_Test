#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int r, c, d;
int arr[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt = 0;

queue<pair<int, int>> q;
vector<pair<int, int>> v;

void rotate()
{
	if (d == 0) d = 3;
	else if (d == 1) d = 0;
	else if (d == 2) d = 1;
	else d = 2;
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}


	q.push({ r, c });

	while (!q.empty())
	{				
	
		v.clear();
		auto cur = q.front();

		// 현재 칸 청소
		if (arr[cur.first][cur.second] != 2)
		{
			arr[cur.first][cur.second] = 2;
			cnt++;
		}


		q.pop();

		// 주변 4칸 중 청소되지 않은 빈 칸 검사
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!arr[nx][ny]) {
				v.push_back({ nx, ny });
			}
				
		}

		// 빈 칸이 없는 경우
		if (v.size() == 0)
		{
			if (d == 0)
			{
				if (arr[cur.first + 1][cur.second] != 1)
				{
					q.push({ cur.first + 1, cur.second });
				}
				else if (arr[cur.first + 1][cur.second] == 1) break;
			}
			else if (d == 1)
			{
				if (arr[cur.first][cur.second - 1] != 1)
				{
					q.push({ cur.first, cur.second - 1 });
				}
				else if (arr[cur.first][cur.second - 1] == 1) break;
			}
			else if (d == 2)
			{
				if (arr[cur.first - 1][cur.second] != 1)
				{
					q.push({ cur.first - 1, cur.second });
				}
				else if (arr[cur.first - 1][cur.second] == 1) break;
			}
			else
			{
				if (arr[cur.first][cur.second + 1] != 1)
				{
					q.push({ cur.first, cur.second + 1 });
				}
				else if (arr[cur.first][cur.second + 1] == 1) break;
			}

		}
		else
		{
			rotate();

			while (1)
			{

				if (d == 0)
				{
					if (!arr[cur.first - 1][cur.second])
					{
						q.push({ cur.first - 1, cur.second });
						break;
					}
					else rotate();
				}
				else if (d == 1)
				{
					if (!arr[cur.first][cur.second + 1])
					{
						q.push({ cur.first, cur.second + 1 });
						break;
					}
					else rotate();
				}
				else if (d == 2)
				{
					if (!arr[cur.first + 1][cur.second])
					{
						q.push({ cur.first + 1, cur.second });
						break;
					}
					else rotate();
				}
				else
				{
					if (!arr[cur.first][cur.second - 1])
					{
						q.push({ cur.first, cur.second - 1 });
						break;
					}
					else rotate();
				}
			}
			
			
		}

	}


	cout << cnt;

}
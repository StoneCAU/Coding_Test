#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, m;
int arr[301][301];
int temp[301][301];
int visited[301][301];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int yy = 0;;
int cnt = 0;

queue<pair<int, int>> q;


void melting()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (!arr[nx][ny]) cnt++;
				}
		
				temp[i][j] = max(0, arr[i][j] - cnt);

			}
		}
	}
		
}

void copy()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}
bool melting_end()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j]) return false;
		}
	}

	return true;
}

bool divide_check()
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (temp[i][j] && !visited[i][j])
			{
				cnt++;

				q.push({ i, j });

				while (!q.empty())
				{
					auto cur = q.front();

					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (!visited[nx][ny] && temp[nx][ny])
						{
							visited[nx][ny] = 1;
							q.push({ nx, ny });
						}
					}

				}
			}
		}
	}


	if (cnt == 1) return false;
	else if (cnt > 1) return true;
	
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (1)
	{
		yy++;

		fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);

		melting();

		if (melting_end()) {
			cout << "0";
			break;
		}

		if (divide_check()) {
			cout << yy;
			break;
		}
		else copy();

	}

	
}
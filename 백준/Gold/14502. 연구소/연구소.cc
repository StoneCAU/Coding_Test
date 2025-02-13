#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int arr[9][9];
int tmp[9][9];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> virus;
vector<pair<int, int>> blank;
queue<pair<int, int>> q;


void bfs(int x, int y)
{
	q.push({ x,y });

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (!tmp[nx][ny])
			{
				tmp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 2) virus.push_back({ i, j });
			if (!arr[i][j]) blank.push_back({ i,j });
		}
	}

	vector<int> idx;
	for (int i = 0; i < blank.size(); i++) idx.push_back(i);
	sort(idx.begin(), idx.end());

	vector<int> temp;
	for (int i = 0; i < 3; i++) temp.push_back(1);
	for (int i = 3; i < blank.size(); i++) temp.push_back(0);


	vector<pair<int, int>> wall;
	int M = 0;

	do
	{
		int cnt = 0;
		wall.clear();
		copy(&arr[0][0], &arr[0][0] + 9 * 9, &tmp[0][0]);

		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 1)
			{
				wall.push_back({ blank[idx[i]].first, blank[idx[i]].second });
				//cout << blank[idx[i]].first << " " << blank[idx[i]].second << "\n";
			}
		}
		//cout << "\n";

		for (int i = 0; i < 3; i++)
		{
			tmp[wall[i].first][wall[i].second] = 1;
		}

		for (int i = 0; i < virus.size(); i++)
		{
			bfs(virus[i].first, virus[i].second);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!tmp[i][j]) cnt++;
			}
		}

		M = max(M, cnt);

	} while (prev_permutation(temp.begin(), temp.end()));

	cout << M;

}
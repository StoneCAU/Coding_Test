#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
int L;
int x = 1;
int y = 1;
int d = 0;
int sec = 0;
int arr[101][101];

vector<pair<int, int>> apple;
queue<pair<int, char>> r;
deque<pair<int, int>> snake;

void rotateL()
{
	if (d == 0) d = 3;
	else if (d == 1) d = 2;
	else if (d == 2) d = 0;
	else d = 1;
}

void rotateR()
{
	if (d == 0) d = 2;
	else if (d == 1) d = 3;
	else if (d == 2) d = 1;
	else d = 0;
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;

		cin >> a >> b;

		apple.push_back({ a, b });
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int num;
		char direction;

		cin >> num >> direction;

		r.push({ num, direction });
	}

	fill(&arr[0][0], &arr[0][0] + 101 * 101, 0);

	for (int i = 0; i < apple.size(); i++)
	{
		arr[apple[i].first][apple[i].second] = 1;
	}

	snake.push_back({ x,y });
	arr[x][y] = 3;

	// 사과: 1, 뱀 몸통: 2, 뱀 머리: 3
	while (!snake.empty())
	{

		sec++;
		
		// 이동(d: 0(동), 1(서), 2(남), 3(북))
		if (d == 0) y++;
		else if (d == 1) y--;
		else if (d == 2) x++;
		else x--;

		// 사과 유무
		if (arr[x][y] == 2) break;
		else if (arr[x][y] == 1)
		{
			snake.push_front({ x,y });
		}
		else
		{
			int tempX = snake.back().first;
			int tempY = snake.back().second;
			arr[tempX][tempY] = 0;
			snake.pop_back();
			snake.push_front({ x,y });
		}

		// 이동
		arr[snake.front().first][snake.front().second] = 3;

		for (int i = 1; i < snake.size(); i++)
		{
			arr[snake[i].first][snake[i].second] = 2;
		}

		// 방향 변환
		if (!r.empty())
		{
			int Tsec = r.front().first;
			char Tdir = r.front().second;

			if (Tsec == sec)
			{
				r.pop();

				if (Tdir == 'L') rotateL();
				else rotateR();
			}
		}


		// 이동 후
		if (x <= 0 || x > n || y <= 0 || y > n) break;
		if (arr[x][y] == 2) break;

	}

	cout << sec;
}
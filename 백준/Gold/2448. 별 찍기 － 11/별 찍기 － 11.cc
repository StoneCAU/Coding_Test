#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
char board[8000][8000];

void draw(int h, int x, int y)
{
	// 제일 작은 삼각형
	if (h == 3) {
		// 꼭짓점
		board[x][y] = '*';
		
		// 두 번째 줄
		board[x + 1][y - 1] = '*';
		board[x + 1][y + 1] = '*';

		// 세 번째 줄
		board[x + 2][y - 2] = '*';
		board[x + 2][y - 1] = '*';
		board[x + 2][y] = '*';
		board[x + 2][y + 1] = '*';
		board[x + 2][y + 2] = '*';

		return;
	}

	draw(h / 2, x, y);
	draw(h / 2, x + h / 2, y - h / 2);
	draw(h / 2, x + h / 2, y + h / 2);

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(&board[0][0], &board[0][0] + 8000 * 8000, ' ');

	cin >> n;

	draw(n, 0, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 2 * n; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}



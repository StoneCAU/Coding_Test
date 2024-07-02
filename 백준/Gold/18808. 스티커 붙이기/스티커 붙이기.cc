#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, m, k;
int sx, sy;
int arr[41][41];
int sticker[41][41];
int rot[41][41];

bool check(int x, int y)
{
	return x < 0 || x - 1 >= n || y < 0 || y - 1 >= m;
}

bool able(int x, int y)
{
	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{
			if (!sticker[i - x][j - y]) continue;
			if (check(i, j)) return false;

			//cout << arr[i][j] << " ";

			if (arr[i][j]) {
				 //cout << i << " " << j << "<<<<<\n";
				return false;
			}
		}
		//cout << "\n";
	}

	return true;
}

void rotateS(int x, int y)
{
	copy(&sticker[0][0], &sticker[0][0] + 41 * 41, &rot[0][0]);

	fill(&sticker[0][0], &sticker[0][0] + 41 * 41, 0);

	if (x == y) {
		for (int i = 0; i < sx; i++)
		{
			for (int j = 0; j < sy; j++)
			{
				sticker[i][j] = rot[sx - j - 1][i];
			}
		}
	}
	else
	{
		for (int i = 0; i < sx; i++)
		{
			for (int j = 0; j < sy; j++)
			{
				sticker[j][sx - 1 - i] = rot[i][j];
			}
		}
		sx = y;
		sy = x;
	}

	
}

void apply(int x, int y)
{
	for (int i = x; i < x + sx; i++)
	{
		for (int j = y; j < y + sy; j++)
		{
			if (!sticker[i - x][j - y]) continue;
			arr[i][j] = 1;
		}
	}
}


// x, y 는 범위 시작 위치(0,0 시작)
void func(int x, int y)
{
	//int temp[41][41];

	//copy(&arr[0][0], &arr[0][0] + 41 * 41, &temp[0][0]);

	if (check(sx, sy))
	{
		rotateS(sx, sy);
		//cout << "rotate!\n";
	}

	int cnt = 0;

	while (cnt != 4)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (able(i, j)) {
					apply(i, j);
					//cout << "apply!\n";
					return;
				}
			}			
		}

		cnt++;
		rotateS(sx, sy);
		//cout << "rotate! 22\n";
			
	}

	if (cnt == 4) return;
	
}



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	fill(&arr[0][0], &arr[0][0] + 41 * 41, 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < k; i++)
	{
		fill(&sticker[0][0], &sticker[0][0] + 41 * 41, 0);

		cin >> sx >> sy;

		for (int j = 0; j < sx; j++)
		{
			for (int a = 0; a < sy; a++)
			{
				cin >> sticker[j][a];
			}
		}

		func(0, 0);

		/*
		cout << "\n";

		rotateS(sx, sy);

		for (int j = 0; j < sx; j++)
		{
			for (int a = 0; a < sy; a++)
			{
				cout << sticker[j][a] << " ";
			}
			cout << "\n";
		}
		

		cout << "\n";

		for (int j = 0; j < n; j++)
		{
			for (int a = 0; a < m; a++)
			{
				cout << arr[j][a] << " ";
			}
			cout << "\n";
		}

		cout << "\n";
		*/
	}
	
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j]) cnt++;
		}
	}

	cout << cnt;

}
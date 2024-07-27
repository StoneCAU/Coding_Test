#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int x, y;
int k;

int arr[21][21];
int dice[7] = { 0, };

void east()
{
	int temp[7];
	copy(dice, dice + 7, temp);

	if (y + 1 >= m) return;
	else y++;

	dice[1] = temp[4];
	dice[3] = temp[1];
	dice[4] = temp[6];


	if (!arr[x][y]) {
		arr[x][y] = temp[3];
		dice[6] = temp[3];
	}
	else
	{
		dice[6] = arr[x][y];
		arr[x][y] = 0;
	}
	

	cout << dice[1] << "\n";
}

void west()
{
	int temp[7];
	copy(dice, dice + 7, temp);

	if (y - 1 < 0) return;
	else y--;

	dice[1] = temp[3];
	dice[4] = temp[1];
	dice[3] = temp[6];

	if (!arr[x][y]) {
		arr[x][y] = temp[4];
		dice[6] = temp[4];
	}
	else
	{
		dice[6] = arr[x][y];
		arr[x][y] = 0;
	}

	cout << dice[1] << "\n";
}

void south()
{
	int temp[7];
	copy(dice, dice + 7, temp);

	if (x + 1 >= n) return;
	else x++;

	dice[1] = temp[2];
	dice[5] = temp[1];
	dice[2] = temp[6];
	
	if (!arr[x][y]) {
		arr[x][y] = temp[5];
		dice[6] = temp[5];
	}
	else
	{
		dice[6] = arr[x][y];
		arr[x][y] = 0;
	}

	cout << dice[1] << "\n";
}

void north()
{
	int temp[7];
	copy(dice, dice + 7, temp);

	if (x - 1 < 0) return;
	else x--;

	dice[1] = temp[5];
	dice[2] = temp[1];
	dice[5] = temp[6];
	
	if (!arr[x][y]) {
		arr[x][y] = temp[2];
		dice[6] = temp[2];
	}
	else
	{
		dice[6] = arr[x][y];
		arr[x][y] = 0;
	}

	cout << dice[1] << "\n";
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;
	
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int op;
		cin >> op;

		if (op == 1) east();
		else if (op == 2) west();
		else if (op == 3) north();
		else south();


	}
}
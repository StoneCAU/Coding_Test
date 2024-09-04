#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int board[3];
int maxdp[3]; // max 전용
int mindp[3]; // min 전용
int maxtemp[3];
int mintemp[3];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cin >> maxtemp[0] >> maxtemp[1] >> maxtemp[2];

	if (n == 1) {
		cout << max(max(maxtemp[0], maxtemp[1]), maxtemp[2]) << " " << min(min(maxtemp[0], maxtemp[1]), maxtemp[2]);
		return 0;
	}

	mintemp[0] = maxtemp[0];
	mintemp[1] = maxtemp[1];
	mintemp[2] = maxtemp[2];

	for (int i = 1; i < n; i++) 
	{
		cin >> board[0] >> board[1] >> board[2];

		maxdp[0] = max(maxtemp[0] + board[0], maxtemp[1] + board[0]);
		maxdp[1] = max(max(maxtemp[0] + board[1], maxtemp[1] + board[1]), maxtemp[2] + board[1]);
		maxdp[2] = max(maxtemp[1] + board[2], maxtemp[2] + board[2]);

		mindp[0] = min(mintemp[0] + board[0], mintemp[1] + board[0]);
		mindp[1] = min(min(mintemp[0] + board[1], mintemp[1] + board[1]), mintemp[2] + board[1]);
		mindp[2] = min(mintemp[1] + board[2], mintemp[2] + board[2]);

		maxtemp[0] = maxdp[0];
		maxtemp[1] = maxdp[1];
		maxtemp[2] = maxdp[2];

		mintemp[0] = mindp[0];
		mintemp[1] = mindp[1];
		mintemp[2] = mindp[2];
	}

	cout << max(max(maxdp[0], maxdp[1]), maxdp[2]) << " " << min(min(mindp[0], mindp[1]), mindp[2]);

	
}



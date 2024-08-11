#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int t;
int m, n, x, y;

int func()
{
	int cnt = 1;
	int cx = 1;
	int cy = 1;

	while (1)
	{
		
		if (x > y && cx > cy && x - y == cx - cy)
		{
			while (1)
			{
				cx++;
				cy++;
				cnt++;

				if (cx == x && cy == y) return cnt;
			}
		}
		else if (x < y && cx < cy && y - x == cy - cx)
		{
			while (1)
			{
				cx++;
				cy++;
				cnt++;

				if (cx == x && cy == y) return cnt;
			}
		}

		int dx = m - cx;
		int dy = n - cy;

		if (dx < dy)
		{
			cx = 1;
			cy = cy + dx + 1;
			cnt += dx + 1;
		}
		else
		{
			if (dx == dy && x == y) return x;

			cy = 1;
			cx = cx + dy + 1;
			cnt += dy + 1;
		}

		if (cx == 1 && cy == 1) return -1;
		if (cx == x && cy == y) return cnt;
	}
	

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> x >> y;

		if (x == 1 && y == 1) {
			cout << "1\n";
			continue;
		}

		int res = func();

		cout << res << "\n";

	}

	

}
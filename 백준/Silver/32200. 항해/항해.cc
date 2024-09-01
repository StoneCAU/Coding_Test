#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	int t;
	int cnt = 0; // 끼니 수는 최대가 되야함
	int trash = 0; // 샌드위치 조각이 최소가 되야함

	cin >> n >> x >> y;

	for (int i = 0; i < n; i++)
	{
		int s;
		cin >> s;

		// x보다 작으면 버림
		if (s < x) trash += s;
		else
		{
			int max_meal = s / x;
			int leftover = s % x;
			int gap = max_meal*y - max_meal*x;

			if (gap < leftover)
			{
				int X = x;

				while (max_meal == s / X && X <= y) X++;

				trash += s % (X - 1);
			}
			

			cnt += max_meal;
		}
	}


	cout << cnt << "\n" << trash;

	return 0;
}



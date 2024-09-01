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

		if (s < x) trash += s;
		else
		{
			int max_meal = s / x;
			int leftover = s % x;
			int t = y - x;

			if (s >= x * max_meal && s <= y * max_meal) leftover = 0;
			else
			{
				leftover = leftover - max_meal * t;
			}

			cnt += max_meal;
			trash += leftover;
		}
	}

	
	cout << cnt << "\n" << trash;

}



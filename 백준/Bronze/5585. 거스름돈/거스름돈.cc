#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int cnt = 0;

	cin >> n;

	n = 1000 - n;

	while (n != 0)
	{
		if (n / 500 > 0)
		{
			cnt += n / 500;
			n %= 500;
		}
		else if (n / 100 > 0)
		{
			cnt += n / 100;
			n %= 100;
		}
		else if (n / 50 > 0)
		{
			cnt += n / 50;
			n %= 50;
		}
		else if (n / 10 > 0)
		{
			cnt += n / 10;
			n %= 10;
		}
		else if (n / 5 > 0)
		{
			cnt += n / 5;
			n %= 5;
		}
		else if (n / 1 > 0)
		{
			cnt += n / 1;
			n %= 1;
		}
	}

	cout << cnt;
	
}



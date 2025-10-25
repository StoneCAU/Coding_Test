#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, s;
int cnt = 0;
int arr[21];

void func(int cur, int sum)
{
	if (cur == n)
	{
		if (sum == s) cnt++;
		return;
	}

	func(cur + 1, sum + arr[cur]);
	func(cur + 1, sum);

}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> arr[i];

	func(0,0);

	if (s == 0) cout << cnt - 1;
	else cout << cnt;

}
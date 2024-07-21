#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, t, p;
	long long Tcnt = 0;

	vector<int> v;

	cin >> n;

	for (int i = 0; i < 6; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	cin >> t >> p;

	for (int i = 0; i < 6; i++)
	{
		if (!v[i]) continue;
		if (v[i] / t == 0) Tcnt++;
		else {
			if (v[i] % t == 0) Tcnt += v[i] / t;
			else Tcnt += v[i] / t + 1;
		}
	}

	cout << Tcnt << "\n" << n / p << " " << n % p;

}
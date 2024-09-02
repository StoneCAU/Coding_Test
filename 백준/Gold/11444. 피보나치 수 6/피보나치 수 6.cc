#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 분할정복을 이용한 거듭제곱
// C^n = C^(n/2) * C^(n/2) (n은 짝수)
// C^n = C^(n-1)/2 * C^(n-1)/2 * C (n은 홀수)
// 피보나치 수는 행렬의 곱셈을 통해 계산할 수 있음
// https://mathnotes.tistory.com/83

vector<pair<unsigned long long, unsigned long long>> mat = { {1, 1}, { 1, 0 } };
long long D = 1000000007;

vector<pair<unsigned long long, unsigned long long>> cal(unsigned long long n)
{

	if (n == 1) return mat;

	vector<pair<unsigned long long, unsigned long long>> t = cal(n / 2);

	if (n % 2 == 0)
	{
		vector<pair<unsigned long long, unsigned long long>> res(2);

		res[0].first = (t[0].first * t[0].first + t[0].second * t[1].first) % D;
		res[0].second = (t[0].first * t[0].second + t[0].second * t[1].second) % D;
		res[1].first = (t[1].first * t[0].first + t[1].second * t[1].first) % D;
		res[1].second = (t[1].first * t[0].second + t[1].second * t[1].second) % D;

		//cout << n << " " << res[0].first << "\n";

		return res;
	}
	else
	{
		vector<pair<unsigned long long, unsigned long long>> temp(2);
		vector<pair<unsigned long long, unsigned long long>> res(2);

		temp[0].first = (t[0].first * t[0].first + t[0].second * t[1].first) % D;
		temp[0].second = (t[0].first * t[0].second + t[0].second * t[1].second) % D;
		temp[1].first = (t[1].first * t[0].first + t[1].second * t[1].first) % D;
		temp[1].second = (t[1].first * t[0].second + t[1].second * t[1].second) % D;

		res[0].first = (temp[0].first + temp[0].second) % D;
		res[0].second = (temp[0].first) % D;
		res[1].first = (temp[1].first + temp[1].second) % D;
		res[1].second = (temp[1].first) % D;

		//cout << n << " " << res[0].first << "\n";

		return res;
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unsigned long long n;
	vector<pair<unsigned long long, unsigned long long>> res;

	cin >> n;

	if (n == 0 || n == 1)
	{
		cout << n;
		return 0;
	}

	res = cal(n-1);
	
	cout << res[0].first % D;
}



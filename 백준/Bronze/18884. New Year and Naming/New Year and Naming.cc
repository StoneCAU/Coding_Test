#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>


using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	vector<string> s;
	vector<string> t;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;

		cin >> str;

		s.push_back(str);
	}

	for (int i = 0; i < m; i++)
	{
		string str;

		cin >> str;

		t.push_back(str);
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		string temp = "";

		int num;
		int a, b;

		cin >> num;

		num--;

		a = num % n;
		b = num % m;

		temp += s[a];
		temp += t[b];

		cout << temp << "\n";
	}

}
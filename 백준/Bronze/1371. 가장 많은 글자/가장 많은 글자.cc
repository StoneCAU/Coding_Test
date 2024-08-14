#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>


using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<char, int> m;

	string s;

	while (getline(cin, s))
	{

		for (int i = 0; i < s.size(); i++)
		{
			if (!m[s[i]]) m[s[i]] = 1;
			else m[s[i]]++;
		}
	}

	int M = 0;

	for (char i = 'a'; i <= 'z'; i++)
	{
		if (M < m[i]) M = m[i];
	}
	
	for (char i = 'a'; i <= 'z'; i++)
	{
		if (m[i] == M) cout << i;
	}



}
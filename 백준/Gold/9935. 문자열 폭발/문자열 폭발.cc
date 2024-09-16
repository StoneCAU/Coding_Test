#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

string chk;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, pung;
	vector<char> v;

	cin >> s >> pung;

	for (int i = 0; i < s.size(); i++)
		{
			char cur = s[i];

			v.push_back(cur);

			if (v.size() >= pung.size())
			{
				
				if (cur == pung[pung.size()-1])
				{
					chk = "";
					
					for (int j = 1; j <= pung.size(); j++)
					{
						chk += v[v.size()-1 - pung.size() + j];
					}

				}


				if (chk == pung)
				{
					for (int j = 0; j < pung.size(); j++) v.pop_back();
					chk = "";

				}
			}

		}
	

	if (!v.size()) cout << "FRULA";
	else
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	}
}



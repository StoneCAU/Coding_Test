#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

string name[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string poke;
	unordered_map<string, int> dic;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> name[i];
		dic[name[i]] = i;
	}

	for (int i = 0; i < m; i++)
	{
		string quest;
		cin >> quest;
		if (isdigit(quest[0])) cout << name[stoi(quest)] << "\n";
		else cout << dic[quest] << "\n";
		
	}

}


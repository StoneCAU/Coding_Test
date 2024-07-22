#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;

	cin >> a >> b >> c;

	cout << stoi(a) + stoi(b) - stoi(c) << "\n";
	cout << stoi(a + b) - stoi(c);

}
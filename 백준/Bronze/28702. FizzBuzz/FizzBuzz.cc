#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int i;
	int cnt = 1;

	for (int j = 1; j <= 3; j++)
	{
		string str;
		
		cin >> str;

		if (str[0] >= '1' && str[0] <= '9')
		{
			i = stoi(str);
			cnt = j;
		}
	}

	while (cnt != 4)
	{
		i++;
		cnt++;
	}

	if (i % 3 == 0)
	{
		if (i % 5 == 0) cout << "FizzBuzz";
		else cout << "Fizz";
	}
	else
	{
		if (i % 5 == 0) cout << "Buzz";
		else cout << i;
	}
}
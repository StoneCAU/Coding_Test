#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int l, c;
char temp[16];
char arr[16];
int m = 0;
int j = 0;

unordered_map<char, int> isused;

void func(int k, int st)
{

	if (k == l) {
		if (!(m > 0 && j > 1)) return;
		for (int i = 0; i < l; i++)
		{
			cout << temp[i];
		}
		cout << "\n";
		return;
	}

	for (int i = st; i < c; i++)
	{
		if (!isused[arr[i]])
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m++;
			else j++;
			isused[arr[i]] = 1;
			temp[k] = arr[i];
			func(k + 1, i + 1);
			isused[arr[i]] = 0;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m--;
			else j--;
		}
	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + c);

	func(0, 0);
}
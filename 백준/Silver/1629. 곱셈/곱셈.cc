#include <bits/stdc++.h>

using namespace std;

long long int a, b, c;

long long int func(long long int b) {
	if (b == 0) return 0;
	if (b == 1) return a % c;

	long long int k = func(b / 2);
	if (b % 2 == 0) return k * k % c;
	else if (b % 2 == 1) return k * k % c * a % c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;

	cout << func(b);
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int team;
	string t;
	
	int min, sec;
	int s;
	int total1 = 0;
	int total2 = 0;
	int score1 = 0;
	int score2 = 0;

	for (int i = 0; i < n; i++) {
		cin >> team >> t;
		min = stoi(t.substr(0, 2));
		sec = stoi(t.substr(3, 2));

		if (score1 > score2) {
			total1 = total1 + (min * 60) + sec - s;
		}
		else if (score1 < score2) {
			total2 = total2 + (min * 60) + sec - s;
		}

		if (team == 1) score1++;
		else score2++;
		s = (min * 60) + sec;
	}

	if (score1 > score2) total1 = total1 + (48 * 60) - s;
	else if (score1 < score2) total2 = total2 + (48 * 60) - s;

	printf("%02d:%02d\n", total1 / 60, total1 % 60);
	printf("%02d:%02d\n", total2 / 60, total2 % 60);
}
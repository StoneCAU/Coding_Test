#include <bits/stdc++.h>

using namespace std;

vector<int> card;

int binarySearch(int target) {
	int low = 0;
	int mid = card.size() / 2;
	int high = card.size() - 1;

	while (low <= high) {
		if (card[mid] == target) return 1;
		else if (card[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	return 0;
}

int main() {
    
    ios::sync_with_stdio(0);
	cin.tie(0);
    
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		card.push_back(num);
	}

	sort(card.begin(), card.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		
		cout << binarySearch(num) << " ";
	}

}
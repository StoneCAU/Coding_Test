#include <bits/stdc++.h>

using namespace std;

string s;

string getWord(vector<int>& sel) {
	string str = "";
	
	string front = s.substr(0, sel[0]);
	string middle = s.substr(sel[0], sel[1] - sel[0]);
	string back = s.substr(sel[1], s[s.size() - 1]);


	reverse(front.begin(), front.end());
	reverse(middle.begin(), middle.end());
	reverse(back.begin(), back.end());

	str += front + middle + back;

	return str;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	vector<string> words;

	vector<int> index;
	vector<int> temp;

	for (int i = 0; i < s.length(); i++) {
		if (i == 0) continue;

		if (i < 3) temp.push_back(0);
		else temp.push_back(1);

		index.push_back(i);
	}

	do {
		vector<int> sel;

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 0) {
				sel.push_back(index[i]);
			}
		}

		words.push_back(getWord(sel));

	} while (next_permutation(temp.begin(), temp.end()));

	sort(words.begin(), words.end());

	cout << words[0];
}
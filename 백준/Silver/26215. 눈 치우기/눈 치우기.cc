#include<bits/stdc++.h>

using namespace std;

int n;
int ans = -1;

vector<int> house;

bool cmp(int a, int b) {
    return a > b;
}

void init() {
    cin >> n;

    for (int i=0;i<n;i++) {
        int num;
        cin >> num;

        house.push_back(num);
    }
}

void solve() {
    int min = 0;

    while (1) {
        if (min > 1440) {
            cout << -1;
            return;
        }

        sort(house.begin(), house.end(), cmp);

        if (house[0] == 0) {
            cout << min;
            return;
        }

        house[0]--;
        house[1]--;

        min++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();
}
#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
set<int> s;

void dfs(int depth, int idx, int sum) {
    if (depth == n) return;

    for (int i=idx;i<n;i++) {
        int cur = v[i];

        s.insert(sum + cur);
        dfs(depth+1, i+1, sum+cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0;i<n;i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    dfs(0, 0, 0);

    for (int i=1;i<=100000 * 20;i++) {
        if (s.find(i) == s.end()) {
            cout << i;
            return 0;
        }
    }
}

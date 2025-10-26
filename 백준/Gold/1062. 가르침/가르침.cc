#include <bits/stdc++.h>

using namespace std;

int n,k;
int ans = 0;
vector<int> words;

void dfs(int idx, int cnt, int mask) {
    if (cnt == k) {
        int readable = 0;
        for (int i=0;i<words.size();++i) {
            if ((words[i] & mask) == words[i]) {
                readable++;
            }
        }

        ans = max(ans, readable);
        return;
    }

    for (int i=idx;i<26;++i) {
        if (mask & (1 << i)) continue;
        dfs(i+1, cnt+1, mask | (1 << i));
    }
}

// anta(___)tica
// a,c,i,n,t 5개 이상은 무조건 배워야함
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;++i) {
        string word;
        cin >> word;

        int mask = 0;
        for (char c : word) {
            mask |= (1 << (c - 'a'));
        }
        words.push_back(mask);
    }

    if (k < 5) {
        cout << 0;
        return 0;
    }

    int basic = 0;
    for (char c : {'a', 'c', 'i', 'n', 't'}) {
        basic |= (1 << (c - 'a'));
    }

    dfs(0,5,basic);

    cout << ans;
}
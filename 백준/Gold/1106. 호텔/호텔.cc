#include <bits/stdc++.h>

using namespace std;

// 도시를 홍보하려고 해요
// i번째 도시를 홍보하는 데에 cost가 주어진다
// 각각 한 번이상 홍보하는데 쓸 수 있다
// 적어도 C명을 늘리기 위해 투자해야하는 돈의 최솟값은?
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n;
    cin >> c >> n;

    vector<pair<int,int>> city(n);
    for (int i=0;i<n;++i) {
        cin >> city[i].first >> city[i].second; // {cost, people}
    }

    vector<int> dp(c + 101, 1e9); // dp[x]: x명의 고객을 얻기 위한 최소 비용
    dp[0] = 0;

    for (int i=0;i<n;++i) {
        int cost = city[i].first;
        int people = city[i].second;

        for (int j=people;j<=c+100;++j) {
            dp[j] = min(dp[j], dp[j - people] + cost);
        }
    }

    int ans = 1e9;
    for (int i=c;i<=c+100;++i) {
        ans = min(ans, dp[i]);
    }

    cout << ans;
}
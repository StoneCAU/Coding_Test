#include<bits/stdc++.h>

using namespace std;

int n;
bool dp[1001]; // dp[i]: i만큼 남았을때 현재 턴 플레이어가 이기면 true

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    dp[4] = true;

    for (int i=5;i<=n;i++) {
        if (!dp[i-1] || !dp[i-3] || !dp[i-4]) dp[i] = true;
        else dp[i] = false;
    }

    if (dp[n]) cout << "SK";
    else cout << "CY";

}
#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long dp[1001];

    dp[1] = 1;
    dp[2] = 3;

    if (n > 2)
    {
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] * 2;
            dp[i] %= 10007;
        }
    }

    cout << dp[n];

}

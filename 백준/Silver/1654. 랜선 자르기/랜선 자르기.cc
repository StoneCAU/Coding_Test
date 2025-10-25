#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector<long long> lan;

// 서로 길이가 다른 K개의 랜선을 보유
// 모두 N개의(N개 이상의) 같은 길이의 랜선으로 구성하기 원함
// 이 때, N개를 만들 수 있는 최대의 랜선의 길이는 몇?
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;++i) {
        int num;
        cin >> num;
        lan.push_back(num);
    }

    long long ans = INT_MIN;
    long long low = 1;
    long long high = *max_element(lan.begin(), lan.end());

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        long long sum = 0;
        for (int i=0;i<n;++i) {
            sum += lan[i] / mid;
        }

        if (sum >= k) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}
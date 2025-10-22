#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n;++i) {
        int num;
        cin >> num;

        A.push_back(num);
    }

    int ans = 0;

    for (int i=0;i<n-2;++i) {
        // 5원 먼저 처리하는 경우
        if (A[i+1] > A[i+2]) {
            int buy = min(A[i], A[i+1] - A[i+2]);
            ans += buy * 5;
            A[i] -= buy;
            A[i+1] -= buy;
        }

        // 그 다음 7원 처리
        int buy = min({A[i], A[i+1], A[i+2]});
        ans += buy * 7;
        A[i] -= buy;
        A[i+1] -= buy;
        A[i+2] -= buy;

        // 남아있는 A[i] 처리
        ans += A[i] * 3;
        A[i] = 0;
    }

    // 마지먹 n-2, n-1번째 처리
    int buy = min(A[n-2], A[n-1]);
    ans += buy * 5;
    A[n-2] -= buy;
    A[n-1] -= buy;

    ans += A[n-2] * 3 + A[n-1] * 3;

    cout << ans;
}
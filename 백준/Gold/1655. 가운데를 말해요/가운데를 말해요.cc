#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> max_pq; // 작은 수들이 들어가야
    priority_queue<int, vector<int>, greater<int>> min_pq; // 큰 수들이 들어가야

    int n;
    cin >> n;

    for (int i=1;i<=n;++i) {
        int num;
        cin >> num;

        if (max_pq.size() == min_pq.size()) {
            max_pq.emplace(num);
        }
        else min_pq.emplace(num);

        if (!min_pq.empty() && max_pq.top() > min_pq.top()) {
            int max_top = max_pq.top();
            int min_top = min_pq.top();
            
            max_pq.pop();
            min_pq.pop();
            
            min_pq.emplace(max_top);
            max_pq.emplace(min_top);
        }

        // 처음 들어왔을 때
        if (min_pq.empty()) {
            cout << max_pq.top() << "\n";
            continue;
        }
        
        if (i % 2 == 1) {
            cout << max_pq.top() << "\n";
        }
        else {
            cout << min(max_pq.top(), min_pq.top()) << "\n";
        }
    }
}
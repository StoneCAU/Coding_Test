#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct comp
{
    bool operator() (int a, int b)
    {
        if (abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, comp> pq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != 0) pq.push(x);
        else
        {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }


    }


}

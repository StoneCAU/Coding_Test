#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, k;
int t = 0;
bool visited[100001];
queue<pair<int,int>> q;

void find(int v)
{
    visited[v] = 1;
    q.push(pair<int,int>(v,0));

    while (!q.empty())
    {
        int now = q.front().first;
        int time = q.front().second;

        q.pop();

        if (now == k) {
            t = time;
            return;
        }

        if (2 * now <= 100000 && !visited[2 * now])
        {
            visited[now] = true;
            q.push(pair<int,int>(2 * now, time + 1));
        }

        if (now + 1 <= 100000 && !visited[now + 1])
        {
            visited[now + 1] = true;
            q.push(pair<int, int>(now + 1, time + 1));
        }

        if (now - 1 >= 0 && !visited[now - 1])
        {
            visited[now - 1] = true;
            q.push(pair<int, int>(now - 1, time + 1));
        }

        t++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    find(n);
    
    cout << t;
}

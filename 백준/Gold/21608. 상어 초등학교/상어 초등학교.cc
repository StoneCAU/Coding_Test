#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int n;
int sum = 0;
int arr[21][21];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cntM = 0;

vector<int> v[401];
vector<pair<int, int>> temp;
vector<pair<int, int>> b;
queue<pair<int, int>> q;

void bfs(int k, int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

        for (int j = 1; j <= 4; j++)
        {
            if (arr[nx][ny] == v[k][j]) cnt++;
        }
    }

    //cout << k << " " << cnt << "\n";

    if (cnt >= cntM) {
        if (cnt > cntM) temp.clear();
        cntM = cnt;
        temp.push_back({ x, y });
    }
}

void blank(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

        if (!arr[nx][ny]) cnt++;
    }

   // cout << x << " " << y << " " << cnt << "\n";

    if (cnt >= cntM)
    {
        if (cnt > cntM) b.clear();
        cntM = cnt;
        b.push_back({ x, y });
    }
}

int findk(int k)
{
    for (int i = 0; i < n * n; i++)
    {
        if (v[i][0] == k) return i;
    }
}

int cal(int k, int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

        for (int j = 1; j <= 4; j++)
        {
            if (arr[nx][ny] == v[findk(k)][j])
            {
                //cout << nx << " " << ny << " " << k << "\n";
                cnt++;
            }
        }

    }

    return cnt; 
}

int main() 
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }


    

    for (int k = 0; k < n * n; k++)
    {
        temp.clear();
        b.clear();
        cntM = 0;
        

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j]) continue;
                bfs(k, i, j);
            }
        }


        if (temp.size() == 1)
        {
            arr[temp.front().first][temp.front().second] = v[k][0];
            continue;
        }
        else
        {
            cntM = 0;
            //cout << temp.size() << "\n";
            for (int i = 0; i < temp.size(); i++)
            {
                blank(temp[i].first, temp[i].second);
            }
        }

        if (b.size() == 1)
        {
            //cout << "gogogo\n";
            arr[b.front().first][b.front().second] = v[k][0];
            //cout << b[0].first << " " << b[0].second << "\n";
            continue;
        }
        else
        {
            sort(b.begin(), b.end());
            arr[b.front().first][b.front().second] = v[k][0];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = cal(arr[i][j], i, j);

            //cout << i << " " << j << " " << cnt << "\n";

            if (cnt == 1) sum += 1;
            else if (cnt == 2) sum += 10;
            else if (cnt == 3) sum += 100;
            else if(cnt == 4) sum += 1000;
        }
    }

    cout << sum;

}
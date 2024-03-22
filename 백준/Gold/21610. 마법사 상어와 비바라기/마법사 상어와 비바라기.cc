#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int n, m;
int arr[52][52];
int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,-1,-1,0,1,1,1,0,-1};

vector<pair<int, int>> v;
vector<pair<int, int>> cloud;
vector<pair<int, int>> temp;

void copy()
{
    for (int i = 0; i < cloud.size(); i++)
    {
        temp.push_back({ cloud[i].first, cloud[i].second });
    }
}

int check(int x, int y)
{
    int xx[] = { 1,1,-1,-1 };
    int yy[] = { -1,1,-1,1 };

    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + xx[i];
        int ny = y + yy[i];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

        if (arr[nx][ny]) cnt++;
    }

    return cnt;

}


void rain(int d, int s)
{
    for (int i = 0; i < cloud.size(); i++)
    {
        for (int j = 0; j < s; j++)
        {
            cloud[i].first += dx[d];
            cloud[i].second += dy[d];

            if (cloud[i].first == 0) cloud[i].first = n;
            else if (cloud[i].first == n + 1) cloud[i].first = 1;

            if (cloud[i].second == 0) cloud[i].second = n;
            else if (cloud[i].second == n + 1) cloud[i].second = 1;
        }
    }

    /*
    for (int i = 0; i < cloud.size(); i++)
    {
        cout << cloud[i].first << " " << cloud[i].second << "<<<\n";
    }
    cout << "\n";
    */

    for (int i = 0; i < cloud.size(); i++)
    {
        arr[cloud[i].first][cloud[i].second]++;
    }

    for (int i = 0; i < cloud.size(); i++)
    {
        arr[cloud[i].first][cloud[i].second] += check(cloud[i].first, cloud[i].second);
    }

    temp.clear();
    copy();
    cloud.clear();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bool flag = false;

            for (int k = 0; k < temp.size(); k++)
            {
                if (temp[k].first == i && temp[k].second == j) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                continue;
            }
            else {
                if (arr[i][j] >= 2) {
                    arr[i][j] -= 2;
                    cloud.push_back({ i,j });
                }
            }
            
        }
    }

    /*for (int i = 0; i < cloud.size(); i++)
    {
        cout << cloud[i].first << " " << cloud[i].second << "\n";
    }*/
    


}



int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cloud.push_back({ n,1 });
    cloud.push_back({ n,2 });
    cloud.push_back({ n-1,1 });
    cloud.push_back({ n-1,2 });


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        temp.clear();
        int d, s;
        cin >> d >> s;

        rain(d, s);
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum += arr[i][j];
        }
    }

    cout << sum;
}
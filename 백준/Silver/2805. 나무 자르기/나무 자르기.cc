#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    vector<long long> tree;

    for (long long i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        
        tree.push_back(num);
    }

    sort(tree.begin(), tree.end());


    long long low = 0;
    long long high = tree[tree.size() - 1];
    long long mid;
    long long sum = 0;

    while (low <= high)
    {
        if (m == high && n == 1)
        {
            mid = 1;
            break;
        }

        sum = 0;
        mid = (low + high) / 2;

        for (long long i = 0; i < tree.size(); i++)
        {
            if(tree[i] - mid > 0)
            sum += (tree[i] - mid);
        }

        if (sum < m) high = mid - 1;
        else if (sum > m) low = mid + 1;
        else break;
    }

    if (sum < m) mid--;

    cout << mid;

}

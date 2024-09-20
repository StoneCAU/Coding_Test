#include<iostream>

using namespace std;

int main()
{
    int n;
    int c, m;
    int res;
    
    cin >> n >> c >> m;
    
    res = c / 2 + m;
    
    if(res <= n) cout << res;
    else cout << n;
    
}
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> v;
    
    while (n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int temp = (int) pow(10, v.size()-1);
    
    for (int i=0;i<v.size();i++) {
        answer += v[i] * temp;
        temp /= 10;
    }
    
    
    return answer;
}
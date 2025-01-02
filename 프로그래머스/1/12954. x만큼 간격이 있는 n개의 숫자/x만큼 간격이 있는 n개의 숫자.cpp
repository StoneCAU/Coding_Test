#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for (int i = 0;i<n;i++) {
        int num = x + x * i;
        answer.push_back(num);
    }
    
    return answer;
}
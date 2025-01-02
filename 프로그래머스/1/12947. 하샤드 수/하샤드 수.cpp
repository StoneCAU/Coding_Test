#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string temp = to_string(x);
    int sum = 0;
    
    for (int i=0;i<temp.length();i++) {
        sum += temp[i] - '0';
    }
    
    if (x % sum == 0) return answer;
    
    return false;
}
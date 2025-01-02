#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool minus = false;
    int size = s.length();
    int temp;
    int start = 0;
    
    if (s[0] == '-') {
        minus = true;
        size--;
        start++;
    }
    
    if (s[0] == '+') {
        size--;
        start++;
    }
    
    temp = (int) pow(10, size-1);
    
    for (int i=start;i<s.length();i++) {
        int num = s[i] - '0';
        answer += num * temp;
        temp /= 10;
    }
    
    if (minus) return -answer;
    
    return answer;
}
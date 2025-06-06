#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    
    while (temp != 1) {
        if (answer == 500) break;
        
        if (temp % 2 == 0) temp /= 2;
        else temp = temp * 3 + 1;
        
        answer++;
    }
    
    if (num != 1 && answer == 500) return -1;
        
    return answer;
}
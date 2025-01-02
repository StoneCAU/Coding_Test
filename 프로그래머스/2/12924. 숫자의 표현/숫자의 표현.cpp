#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1;i<=n;i++) {
        int sum = 0;
        int start = i;
        
        for(int j=start;j<=n;j++) {
            sum += j;
            if (sum >= n) break;
        }
        if (sum == n) answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int arr[10] = {0,};
    
    for (int i = 0;i<numbers.size();i++) {
        if (arr[numbers[i]] == 0) arr[numbers[i]] = 1;
    }
    
    for(int i=1;i<=9;i++) {
        if (arr[i] == 0) answer += i;
    }
    
    return answer;
}
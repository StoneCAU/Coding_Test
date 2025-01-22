#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i=left;i<=right;i++) {
        long long li = i / n; // i 번쨰 집합의
        long long lj = i % n; // 0 ~ n-1 index

        // li번째 집합에서는 li번째 요소까지 숫자가 li+1로 같고
        // 그 뒤로는 (li+1) + lj-li = lj + 1

        if (lj <= li) answer.push_back(li+1);
        else answer.push_back(lj+1);
    }
    
    
    return answer;
}
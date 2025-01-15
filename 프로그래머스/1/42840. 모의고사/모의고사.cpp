#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    
    int one = 0;
    int two = 0;
    int three = 0;
    
    for (int i=0;i<answers.size();i++) {
        int ans = answers[i];
        
        if (first[i % first.size()] == ans) one++;
        if (second[i % second.size()] == ans) two++;
        if (third[i % third.size()] == ans) three++;
    }
    
    int M = max(max(one, two), three);
    
    if (one == M) answer.push_back(1);
    if (two == M) answer.push_back(2);
    if (three == M) answer.push_back(3);
    
    return answer;
}
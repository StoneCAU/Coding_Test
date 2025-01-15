#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i=0;i<commands.size();i++) {
        vector<int> temp = array;

        int start = commands[i][0] - 1;
        int end = commands[i][1] - 1;
        int target = commands[i][2] - 1;
        
        temp.erase(temp.begin(), temp.begin() + start);
        temp.erase(temp.begin() + end - start + 1, temp.end());
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[target]);
    }
    
    return answer;
}
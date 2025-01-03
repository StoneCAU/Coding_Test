#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> map;
    
    map[words[0]] = true;
    
    for(int i=1;i<words.size();i++) {
        if (map[words[i]] || words[i-1][words[i-1].length()-1] != words[i][0]) {
            int round = (i+1) / n;
            int order = (i+1) % n;
            if ((i+1) % n != 0) round++;
            else order = n;
            
            answer.push_back(order);
            answer.push_back(round);
            return answer;
        }
        
        map[words[i]] = true;
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
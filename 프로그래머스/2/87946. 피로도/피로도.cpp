#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> v;
    
    for (int i=0;i<dungeons.size();i++) {
        v.push_back(i);
    }
    
    do {
        vector<int> order;
        
        for(int i=0;i<v.size();i++) {
            order.push_back(v[i]);
        }
        
        int temp = k;
        
        for (int i=0;i<order.size();i++) {
            int index = order[i];
            int need = dungeons[index][0];
            int use = dungeons[index][1];
            
            if (temp < need) {
                answer = max(answer, i);
                break;
            }
            
            if (i == order.size() - 1) return order.size();

            temp -= use; 
        }
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}